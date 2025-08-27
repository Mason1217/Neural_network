#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Layer.h"

#define DEBUG 1

struct Layer *init_linear_layer(const int input_dim, const int output_dim)
{
    struct Layer *layer = (struct Layer*)malloc(sizeof(struct Layer));

    layer->type = LINEAR;
    layer->input_dim = input_dim;
    layer->output_dim = output_dim;
    layer->params = init_linear_params(input_dim, output_dim);
    layer->forward = linear_forward;

    return layer;
}

struct Layer *init_relu_layer(const int input_dim, const int output_dim)
{
    struct Layer *layer = (struct Layer*)malloc(sizeof(struct Layer));
    
    layer->type = RELU;
    layer->input_dim = input_dim;
    layer->output_dim = output_dim;
    layer->params = NULL;
    layer->forward = relu_forward;

    return layer;
}

struct Layer *init_softmax_layer(const int input_dim, const int output_dim)
{
    struct Layer *layer = (struct Layer*)malloc(sizeof(struct Layer));

    layer->type = SOFTMAX;
    layer->input_dim = input_dim;
    layer->output_dim = output_dim;
    layer->params = NULL;
    layer->forward = softmax_forward;

    return layer;
}

struct LinearParams *init_linear_params(const int input_dim, const int output_dim)
{
    struct LinearParams *params = (struct LinearParams*)malloc(sizeof(struct LinearParams));
    params->Weight = random_create_matrix(input_dim, output_dim);
    params->Bias = random_create_matrix(1, output_dim);
    return params;
}

struct Matrix *linear_forward(const struct Matrix *X, const void *params)
{
    return add_mat(mul_mat(X, ((struct LinearParams*)params)->Weight),
                   ((struct LinearParams*)params)->Bias);
}

struct Matrix *relu_forward(const struct Matrix *X, const void *params)
{
    struct Matrix *res = init_mat(X->rows, X->cols);
    for (int i = 0; i < res->rows; i++)
        for (int j = 0; j < res->cols; j++)
            res->entries[i][j] = (X->entries[i][j] <= 0) ? 0 : X->entries[i][j];
    return res;
}

struct Matrix *softmax_forward(const struct Matrix *X, const void *params)
{
    struct Matrix *res = init_mat(X->rows, X->cols);
    TYPE sum = 0;
    for (int i = 0; i < X->cols; i++) {
        res->entries[0][i] = exp(X->entries[0][i]);
        sum += res->entries[0][i];
    }
    for (int i = 0; i < X->cols; i++) res->entries[0][i] /= sum;
    
    return res;
}