#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Block.h"

#define DEBUG 1

struct Block *init_block(struct Layer **layers, int num_layers)
{
    struct Block *block = (struct Block*)malloc(sizeof(struct Block));
    
    block->input_dim = layers[0]->input_dim;
    block->output_dim = layers[num_layers-1]->output_dim;
    block->hidden_dim = layers[0]->output_dim;
    block->num_layers = num_layers;
    block->layers = layers;

    return block;
}

struct Matrix *forward_block(const struct Block *block, const struct Matrix *X)
{
    struct Matrix *Y = init_mat(X->rows, X->cols);
    memcpy(Y, X, sizeof(struct Matrix));
    for (int i = 0; i < block->num_layers; i++) {
        Y = block->layers[i]->forward(Y, block->layers[i]->params);
        #if DEBUG >= 2
        print_matrix(Y);
        printf("\n");
        #endif
    }
    return Y;
}

void print_block(const struct Block *block)
{
    printf("\nnumber of layers: %d\n", block->num_layers);
    printf("in_d(%d) | h_d(%d) | out_d(%d)\n", block->input_dim,
           block->hidden_dim, block->output_dim);
    for (int i = 0; i < block->num_layers; i++) {
        struct Layer *layer = block->layers[i];
        switch (layer->type) {
            case LINEAR:
                printf("linear(%d, %d)", layer->input_dim, layer->output_dim);
                break;
            case RELU:
                printf("relu(%d, %d)", layer->input_dim, layer->output_dim);
                break;
            case SOFTMAX:
                printf("softmax(%d, %d)", layer->input_dim, layer->output_dim);
                break;
        }
        if (i < block->num_layers-1)
            printf(" -> ");
        else
            printf("\n\n");
    }
}