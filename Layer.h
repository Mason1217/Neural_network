#ifndef LAYER_H
#define LAYER_H

#include "Matrix.h"
#include "definitions.h"

#define LAYER_TYPE {LINEAR, RELU, SOFTMAX}

struct Layer {
    enum LAYER_TYPE type;
    int input_dim;
    int output_dim;
    void *params;
    struct Matrix *(*forward)(const struct Matrix*, const void*);
};

struct Layer *init_linear_layer(const int input_dim, const int output_dim);
struct Layer *init_relu_layer(const int input_dim, const int output_dim);
struct Layer *init_softmax_layer(const int input_dim, const int output_dim);

struct LinearParams {
    struct Matrix *Weight;
    struct Matrix *Bias;
};

struct LinearParams *init_linear_params(const int input_dim, const int output_dim);

struct Matrix *linear_forward(const struct Matrix *X, const void *params);
struct Matrix *relu_forward(const struct Matrix *X, const void *params);

/**
 * Expected X's shape to be (1, C).
 */
struct Matrix *softmax_forward(const struct Matrix *X, const void *params);

#endif