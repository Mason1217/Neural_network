matrix_test: matrix_test.o Matrix.o utilities.o activation_functions.o
	gcc -o matrix_test matrix_test.o Matrix.o utilities.o activation_functions.o
matrix_test.o: matrix_test.c Matrix.h activation_functions.h utilities.h
	gcc -c matrix_test.c
Matrix.o: Matrix.c utilities.h definitions.h
	gcc -c Matrix.c
utilities.o: utilities.c
	gcc -c utilities.c
activation_functions.o: activation_functions.c definitions.h
	gcc -c activation_functions.c