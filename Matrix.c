#include "utilities.h"
#include "Matrix.h"
#define DEBUG 1

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

    mat = (struct Matrix*)malloc(sizeof(struct Matrix));
    mat->rows = rows;
    mat->cols = columns;
    mat->entries = (float**)malloc(rows * sizeof(float*));
    for (int i = 0; i < rows; i++)
        mat->entries[i] = (float*)malloc(columns * sizeof(float));
    #if DEBUG
    printf("rows: %d | columns: %d\n", mat->rows, mat->cols);
    #endif

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            float entry;
            do {
                #if DEBUG
                printf("entry_%d%d: ", i, j);
                #endif
            } while (!read_float(&entry));
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

void print_matrix(struct Matrix *mat)
{
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