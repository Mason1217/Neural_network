#ifndef BLOCK_H
#define BLOCK_H

#include "Layer.h"
#include "definitions.h"

struct Block {
    int input_dim;
    int output_dim;
    int hidden_dim;
    int num_layers;
    struct Layer **layers;
};

struct Block *init_block(struct Layer **layers, int num_layers);
                      
struct Matrix *forward_block(const struct Block *block, const struct Matrix *X);

void print_block(const struct Block *block);

#endif