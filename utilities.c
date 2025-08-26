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