double** allocate_matrix(int rows, int cols);
void copy_matrix(double** copy, double** matrix, int rows, int cols);
int* get_matrix_size(int set_no_rows);
double** fill_matrix(int rows, int cols);
void print_matrix(double** matrix, int rows, int cols);
void free_matrix(double** matrix, int rows);
void exchange_matrix_rows(double** matrix, int no_cols, int row1, int row2);
