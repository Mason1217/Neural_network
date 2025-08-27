#include <stdlib.h>
#include <math.h>
#include "activation_functions.h"

TYPE ReLU(const TYPE x)
{
    return (x <= 0) ? 0 : x;
}

TYPE *softmax(const TYPE *nums, const int len)
{
    TYPE sum = 0;
    for (int i = 0; i < len; i++)
        sum += nums[i];
    TYPE *res = (TYPE*)malloc(len * sizeof(TYPE));
    for (int i = 0; i < len; i++)
        res[i] = nums[i] / sum;
    return res;
}