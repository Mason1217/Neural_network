#include <stdlib.h>
#include <stdio.h>
#include "Matrix.h"
#include "Layer.h"

#define DEBUG 1

struct Layer *init_layer(const int input_dim, const int output_dim,
                         TYPE (*activation_func)(const TYPE))
{
    struct Layer *layer = (struct Layer*)malloc(sizeof(struct Layer));
    layer->input_dim = input_dim;
    layer->output_dim = output_dim;
    layer->Bias = random_create_matrix(1, output_dim);
    layer->Weight = random_create_matrix(input_dim, output_dim);
    layer->activation_func = activation_func;
    return layer;
}

struct Matrix *forward_layer(const struct Layer *layer, const struct Matrix *X)
{
    if (X->rows != 1 || X->cols != layer->input_dim) {
        #if DEBUG
        printf("%s: X has shape(%d, %d) while layer's input dim is %d",
               __func__, X->rows, X->cols, layer->input_dim);
        #endif
        return NULL;
    }
    struct Matrix *Y = init_mat(1, layer->output_dim);

    Y = add_mat(mul_mat(X, layer->Weight), layer->Bias);
    for (int i = 0; i < Y->cols; i++)
        Y->entries[0][i] = layer->activation_func(Y->entries[0][i]);
    
    return Y;
}