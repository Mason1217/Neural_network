#ifndef MATRIX_H
#define MATRIX_H

#include "definitions.h"

struct Matrix {
    int rows;
    int cols;
    TYPE **entries;
};

/**
 * Allocate space for new matrix with given rows and cols.
 */
struct Matrix *init_mat(const int rows, const int cols);

/**
 * Type number of rows -> number of columns -> entries.
 */
struct Matrix *typing_create_matrix();

struct Matrix *random_create_matrix(const int rows, const int cols);

void print_matrix(const struct Matrix *mat);

/**
 * @return Result matrix which is the sum of mat_1 & mat_2.
 */
struct Matrix *add_mat(const struct Matrix *mat_1, const struct Matrix *mat_2);

/**
 * @return Result matrix of multiplication from mat_l * mat_r.
 */
struct Matrix *mul_mat(const struct Matrix *mat_l, const struct Matrix *mat_r);

#endif