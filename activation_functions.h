#ifndef ACTIVATION_FUNCTIONS_H
#define ACTIVATION_FUNCTIONS_H

#include "definitions.h"

TYPE ReLU(const TYPE x);

TYPE *softmax(const TYPE *nums, const int len);

#endif