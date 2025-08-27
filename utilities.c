#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"

int read_int(int *number)
{
    if (!scanf("%d", number)) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return 0;
    }
    return 1;
}

int read_float(float *number)
{
    if (!scanf("%f", number)) {
        int c;
        while((c = getchar()) != '\n' && c != EOF);
        return 0;
    }
    return 1;
}

int read_double(double *number)
{
    if (!scanf("%lf", number)) {
        int c;
        while((c = getchar()) != '\n' && c != EOF);
        return 0;
    }
    return 1;
}

TYPE gen_random()
{
    return (RANDOM_UPPER_BOUND - RANDOM_LOWER_BOUND) * rand() / (RAND_MAX+1.0) + RANDOM_LOWER_BOUND;
}