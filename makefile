matrix_test: matrix_test.o Matrix.o utilities.o
	gcc -o matrix_test matrix_test.o Matrix.o utilities.o
matrix_test.o: matrix_test.c Matrix.h
	gcc -c matrix_test.c
Matrix.o: Matrix.c utilities.h
	gcc -c Matrix.c
utilities.o: utilities.c
	gcc -c utilities.c