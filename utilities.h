#ifndef UTILITIES_H
#define UTILITIES_H

#include "definitions.h"

/**
 * @return 0 when failed; otherwise when succeeded.
 */
int read_int(int *number);

/**
 * @return 0 when failed; otherwise when succeeded.
 */
int read_float(float *number);

int read_double(double *number);

TYPE gen_random();

#endif