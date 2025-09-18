#include <stdio.h>

int main() {
    int matrix[3][3];
    int determinant;
    
    printf("Enter the matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    printf("The matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    determinant = 
        matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
        - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
        + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    
    printf("Matrix determinant: %d\n", determinant);
    
    if (determinant == 0) {
        printf("Matrix can not be inverted\n");
    } else {
        printf("Matrix is invertible\n");
    }
    
    return 0;
}