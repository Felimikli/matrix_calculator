#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int* get_matrix_size(int set_no_rows){
    int* matrix_size = (int*)malloc(2 * sizeof(int)) ;
    printf("Number of rows: ");
    scanf("%d",&matrix_size[0]);
    printf("Number of columns: ");
    scanf("%d",&matrix_size[1]);

    if(set_no_rows && set_no_rows != matrix_size[0]){
        printf("invalid number of rows, it must be equal to numbre of rows of first matrix (%d)\n", set_no_rows);
        get_matrix_size(set_no_rows);
    } else{
        return matrix_size;
    }
}

double** fill_matrix(int* matrix_size) {

    double** matrix = malloc(matrix_size[0] * sizeof(double*));
    for(int i = 0; i < matrix_size[0]; i++) {
        matrix[i] = malloc(matrix_size[1] * sizeof(double));
    }

    for(int j = 0; j < matrix_size[0]; j++) {
        for(int k = 0; k < matrix_size[1]; k++) {
            printf("type coordinate (%d, %d): ", j+1, k+1);
            scanf(" %lf", &matrix[j][k]);
        }
    }
    return matrix;
}


double** multiply(double** first_matrix, double** second_matrix, int result_matrix_rows, int middle_cols_rows, int result_matrix_cols) {

    double** result_matrix = calloc(result_matrix_rows, sizeof(double*));
    for(int i = 0; i < result_matrix_rows; i++) {
        result_matrix[i] = calloc(result_matrix_cols, sizeof(double));
    }

    for(int m = 0; m < result_matrix_rows; m++) {
        for(int p = 0; p < result_matrix_cols; p++) {
            for(int n = 0; n < middle_cols_rows; n++) {
                result_matrix[m][p] += first_matrix[m][n] * second_matrix[n][p];
            }
        }
    }
    return result_matrix;
}


void print_matrix(double** matrix, int* matrix_size) {
    for(int i = 0; i < matrix_size[0]; i++) {
        for(int j = 0; j < matrix_size[1]; j++) {
            printf("%.2lf\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){

    printf("write the size of your first matrix:\n");
    int* first_matrix_size = get_matrix_size(0);
    printf("\nfirst matrix size:\nrows: %d, cols: %d\n\n", first_matrix_size[0], first_matrix_size[1]);

    printf("write the size of your second matrix:\n");
    int* second_matrix_size = get_matrix_size(first_matrix_size[1]);
    printf("\nsecond matrix size:\nrows: %d, cols: %d\n\n", second_matrix_size[0], second_matrix_size[1]);
        
    printf("fill your first matrix:\n");
    double** first_matrix = fill_matrix(first_matrix_size);
    printf("\n");
    print_matrix(first_matrix, first_matrix_size);

    printf("fill your second matrix:\n");
    double** second_matrix = fill_matrix(second_matrix_size);
    printf("\n");
    print_matrix(second_matrix, second_matrix_size);

    int* result_matrix_size = (int*)malloc(2 * sizeof(int));
    result_matrix_size[0] = first_matrix_size[0];
    result_matrix_size[1] = second_matrix_size[1];

    
    clock_t start, end;
    double time_spent;
    start = clock(); // Start measuring time


    double** result_matrix = multiply(first_matrix, second_matrix, result_matrix_size[0], first_matrix_size[1], result_matrix_size[1]);


    end = clock(); // Stop measuring time
    time_spent = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nTime taken to multiply: %lf seconds\n------------------------------------------------------\n\n", time_spent);

    printf("result matrix:\n");
    print_matrix(result_matrix, result_matrix_size);

// free sizes
    free(first_matrix_size);
    free(second_matrix_size);
    free(result_matrix_size);

//free matrices rows and elements
    for (int i = 0; i < first_matrix_size[0]; i++) {
        free(first_matrix[i]);
    }
    free(first_matrix);

    for (int j = 0; j < second_matrix_size[0]; j++) {
        free(second_matrix[j]);
    }
    free(second_matrix);

    for(int k = 0; k < first_matrix_size[0]; k++) {
        free(result_matrix[k]);
    }
    free(result_matrix);

    char exit_input;
    printf("to continue press anything,\nto exit press: q\n");
    scanf(" %c", &exit_input);
    if(exit_input == 'q') {
        return 0;
    } else {
        main();
    }
}
