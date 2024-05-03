#include <stdio.h>
#include <math.h>
#include <time.h>

int get_size(void){
    int size;
    printf("Write the size of the square matrix (for 3x3 matrix type 3): \n");
    scanf("%d", &size);
    return size;
};

double get_determinant(int matrix_size, double matrix[matrix_size][matrix_size]){
    double det = 0.0;
    int sign;
    int minor_size = matrix_size-1;
    double minor[minor_size][minor_size];

    if(matrix_size == 2){
        det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]); 
        return det;
    }

    for (int i = 0; i < matrix_size; i++) {
        int minor_row = 0;
        int minor_col = 0;

        for (int j = 1; j < matrix_size; j++) {
            minor_col = 0;
            for (int k = 0; k < matrix_size; k++) {
                if(k != i) {
                    minor[minor_row][minor_col] = matrix[j][k];
                    sign = (i % 2 == 0) ? 1 : -1;
                    minor_col++;
                }
            }
            minor_row++;        
        }
        det += sign * get_determinant(minor_size, minor) * matrix[0][i];
    }
    return det;
}

void print_matrix(int matrix_size, double matrix[matrix_size][matrix_size]){
    printf("Your matrix:\n");
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            printf("%.2lf\t", matrix[i][j]);
        };
        printf("\n");
    };
};

void main(void){
    int matrix_size = get_size();
    double matrix[matrix_size][matrix_size];


    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {

            printf("Type coordinate (%d, %d): ", i+1 , j+1);
            scanf("%lf", &matrix[i][j]);
        };
    };

    print_matrix(matrix_size, matrix);

    
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Start measuring time




    printf("DETERMINANT: %lf", get_determinant(matrix_size, matrix));




     end = clock(); // Stop measuring time

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nTime taken to calculate determinant: %lf seconds\n", cpu_time_used);
    
}