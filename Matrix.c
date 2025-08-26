#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"
#include "Matrix.h"

#define DEBUG 2
#define SEP_LINE "------------\n"

#define EXPAND_READ_FUNC(t) read_##t
#define READ_FUNC(t) EXPAND_READ_FUNC(t)
#define ENTRY_WIDTH 5
#define ENTRY_PRECISION 2
#define TILE_SIZE 8

static void _mul_mat_op(struct Matrix *res_mat, const struct Matrix *mat_l, const struct Matrix *mat_r);

struct Matrix *init_mat(const int rows, const int cols)
{
    struct Matrix *mat = (struct Matrix*)malloc(sizeof(struct Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->entries = (TYPE**)malloc(rows * sizeof(TYPE*));
    for (int i = 0; i < rows; i++)
        mat->entries[i] = (TYPE*)malloc(cols * sizeof(TYPE));
    return mat;
}

struct Matrix *typing_create_matrix()
{
    int rows, columns;
    struct Matrix *mat;

    do {
        #if DEBUG
        printf("Number of rows: ");
        #endif
    } while (!read_int(&rows));

    do {
        #if DEBUG
        printf("Number of columns: ");
        #endif
    } while (!read_int(&columns));

    mat = init_mat(rows, columns);
    #if DEBUG
    printf("rows: %d | columns: %d\n", mat->rows, mat->cols);
    #endif

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            TYPE entry;
            do {
                #if DEBUG
                printf("entry_%d%d: ", i, j);
                #endif
            } while (!READ_FUNC(TYPE)(&entry));
            mat->entries[i][j] = entry;
        }
    }
    #if DEBUG >= 2
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%*.*f ",ENTRY_WIDTH, ENTRY_PRECISION, mat->entries[i][j]);
        }
        printf("\n");
    }
    #endif
    return mat;
}

void print_matrix(const struct Matrix *mat)
{
    if (mat == NULL) {
        #if DEBUG
        printf("%s: mat is NULL.\n", __func__);
        #endif
        printf("NULL\n");
        return;
    }

    for (int i = 0; i < mat->rows; i++) {
        char edge = (i == 0 || i == mat->rows-1) ? '[' : '|';
        printf("%c", edge);
        for (int j = 0; j < mat->cols; j++) {
            printf("%*.*f ",ENTRY_WIDTH, ENTRY_PRECISION, mat->entries[i][j]);
        }
        edge = (i == 0 || i == mat->rows-1) ? ']' : '|';
        printf("%c\n", edge);
    }
}

struct Matrix *add_mat(const struct Matrix *mat_1, const struct Matrix *mat_2)
{
    if (mat_1->rows != mat_2->rows || mat_1->cols != mat_2->cols) {
        #if DEBUG
        printf("%s: mat_1 has shape (%d, %d) while mat_2 has shape (%d, %d).\n",
               __func__, mat_1->rows, mat_1->cols, mat_2->rows, mat_2->cols);
        #endif
        return NULL;
    }
    int rows = mat_1->rows, cols = mat_1->cols;
    struct Matrix *result = init_mat(rows, cols);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result->entries[i][j] = mat_1->entries[i][j] + mat_2->entries[i][j];
        }
    }
    return result;
}

struct Matrix *mul_mat(const struct Matrix *mat_l, const struct Matrix *mat_r)
{
    #if DEBUG >= 2
    printf("%s: \n", __func__);
    print_matrix(mat_l);
    printf("%s", SEP_LINE);
    print_matrix(mat_r);
    printf("%s", SEP_LINE);
    #endif

    if (mat_l->cols != mat_r->rows) {
        #if DEBUG
        printf("%s: mat_l has shape (%d, %d) while mat_r has shape (%d, %d).\n",
               __func__, mat_l->rows, mat_l->cols, mat_r->rows, mat_r->cols);
        #endif
        return NULL;
    }
    int rows = mat_l->rows, cols = mat_r->cols;
    struct Matrix *result = init_mat(rows, cols);

    _mul_mat_op(result, mat_l, mat_r);
    return result;
}

static void _mul_mat_op(struct Matrix *res_mat, const struct Matrix *mat_l, const struct Matrix *mat_r)
{
    for (int I = 0; I < res_mat->rows; I += TILE_SIZE) {
        for (int J = 0; J < res_mat->cols; J += TILE_SIZE) {
            for (int K = 0; K < mat_l->cols; K += TILE_SIZE) {
                for(int i = I; i < (I + TILE_SIZE) && i < res_mat->rows; i++) {
                    for (int j = J; j < (J + TILE_SIZE) && j < res_mat->cols; j++) {
                        float entry = 0;
                        for (int k = 0; k < (K + TILE_SIZE) && k < mat_l->cols; k++) {
                            entry += mat_l->entries[i][k] * mat_r->entries[k][j];
                        }
                        res_mat->entries[i][j] = entry;
                    }
                }
            }
        }
    }
}