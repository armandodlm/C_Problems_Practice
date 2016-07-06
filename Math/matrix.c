#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct matrix_t{
	int **matrix;
	uint16_t rows;
	uint16_t columns;
}matrix_t;

matrix_t *initMatrix(uint16_t rows, uint16_t columns);
void destroyMatrix(matrix_t *m);

matrix_t *multiplyMatrix(matrix_t *a, matrix_t *b);

void printMatrix(matrix_t *m);

matrix_t *initMatrix(uint16_t rows, uint16_t columns){

	matrix_t *m = (matrix_t *)malloc(sizeof(matrix_t));
	m->matrix = (int **)malloc(sizeof(int *)*rows);
	uint16_t iter = 0;
	
	for(iter = 0; iter < rows; iter++){
		m->matrix[iter] = (int *)calloc(columns,sizeof(int));
	}

	m->rows = rows;
	m->columns = columns;

	return m;
}


void destroyMatrix(matrix_t *m){
	if(m){
		uint16_t iter = 0;
		for(iter = 0; iter < m->rows; iter++){
			free(m->matrix[iter]);
		}
		free(m);
	}
}

void printMatrix(matrix_t *m){
	if(m){
		uint16_t iter;
		uint16_t cols; 
		for(iter = 0; iter < m->rows; iter++){
			printf("[ ");
			for(cols = 0; cols < m->columns; cols++){
				printf(" %02d ",m->matrix[iter][cols]);
			}
			printf(" ] \n");
		}
	}else{
		printf("This is not a valid matrix\n");
	}
}


matrix_t *multiplyMatrix(matrix_t *a, matrix_t *b){

	matrix_t *result = NULL;

	if(a && b){
		if(a->columns == b->rows){
			uint16_t rows = a->rows;
			uint16_t columns = b->columns;
			result = initMatrix(rows,columns);

			uint16_t iterRowsA;
			uint16_t iterColsA; 
			uint16_t iterColsB;
			for(iterColsB = 0; iterColsB < b->columns; iterColsB++){
				// colsA will always equal rowsB so just use colsA
				for(iterRowsA = 0; iterRowsA < a->rows; iterRowsA++){
					int value = 0;
					for(iterColsA = 0; iterColsA < a->columns; iterColsA++){
						value += a->matrix[iterRowsA][iterColsA] * b->matrix[iterColsA][iterColsB];
					}
					result->matrix[iterRowsA][iterColsB] = value;
				}
			}

		}else{
			printf("These two matrices do not meet the dimention requirements\n");
		}
	}


	return result;
}


int main(int argc, char **args){
	matrix_t *a = initMatrix(2,3);
	matrix_t *b = initMatrix(3,2);

	a->matrix[0][0] = 1;
	a->matrix[0][1] = 2;
	a->matrix[0][2] = 3;
	a->matrix[1][0] = 4;
	a->matrix[1][1] = 5;
	a->matrix[1][2] = 6;


	b->matrix[0][0] = 5;
	b->matrix[1][0] = 6;
	b->matrix[2][0] = 7;
	b->matrix[0][1] = 8;
	b->matrix[1][1] = 9;
	b->matrix[2][1] = 10;
	
	matrix_t *c = multiplyMatrix(a,b);
	printf("Matrix a:\n");
	printMatrix(a);
	printf("Matrix b:\n");
	printMatrix(b);
	printf("Matrix c:\n");
	printMatrix(c);
	destroyMatrix(a);
	destroyMatrix(b);
	destroyMatrix(c);
}


