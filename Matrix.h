#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"

#define ENTRY_WIDTH 5
#define ENTRY_PRECISION 2

struct Matrix {
    int rows;
    int cols;
    float **entries;
};

/**
 * Type number of rows -> number of columns -> entries.
 */
struct Matrix *typing_create_matrix();

void print_matrix(struct Matrix *mat);

#endif