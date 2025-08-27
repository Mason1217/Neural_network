#ifndef LAYER_H
#define LAYER_H

#include "Matrix.h"
#include "definitions.h"

struct Layer {
    int input_dim;
    int output_dim;
    struct Matrix *Bias;
    struct Matrix *Weight;
    TYPE (*activation_func)(const TYPE);
};

struct Layer *init_layer(const int input_dim, const int output_dim,
                         TYPE (*activation_func)(const TYPE));

/**
* Forward input matrix(X)(1, input dim) through given layer.
* @return Output matrix(Y)(1, output dim)
*/
struct Matrix *forward_layer(const struct Layer *layer, const struct Matrix *X);

#endif