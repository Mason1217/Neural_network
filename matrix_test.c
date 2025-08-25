#include "Matrix.h"

int main(int argc, char *argv[])
{
    struct Matrix *mat_1 = typing_create_matrix();
    struct Matrix *mat_2 = typing_create_matrix();
    print_matrix(mul_mat(mat_1, mat_2));
    print_matrix(mul_mat(mat_2, mat_1));
}