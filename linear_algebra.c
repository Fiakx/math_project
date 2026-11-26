#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n, m;
    double **tab;
} Matrix;

Matrix create_matrix(int n, int m) {
    Matrix M = {n, m, malloc(n * sizeof(double *))};
    for (int i = 0; i < n; i++)
        M.tab[i] = calloc(m, sizeof(double));
    return M;
}

void free_matrix(Matrix M) {
    for (int i = 0; i < M.n; i++)
        free(M.tab[i]);
    free(M.tab);
}

void print_matrix(Matrix M) {
    for (int i = 0; i < M.n; i++) {
        for (int j = 0; j < M.m; j++)
            printf("%8.3f ", M.tab[i][j]);
        printf("\n");
    }
}

int main(void) {
    int n = 4;
    Matrix M = create_matrix(n, n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M.tab[i][j] = i * n + j;

    print_matrix(M);
    free_matrix(M);

    return EXIT_SUCCESS;
}
