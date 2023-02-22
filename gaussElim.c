#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void printMatrix(float matrix[][MAX_SIZE + 1], int rows, int cols)
{
    int i, j;
    printf("Matrix is:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    float matrix[MAX_SIZE][MAX_SIZE + 1], sol[MAX_SIZE], fac;
    int i, j, k, n;
    printf("Enter the number of equations: ");
    scanf("%d", &n);
    printf("Enter the augmented matrix row wise:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            printf("Enter element of row %d and col %d: ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }
    printMatrix(matrix, n, n + 1);
    // Gaussian elimination method
    for (i = 0; i < n; i++)
    {
        if (matrix[i][i] == 0)
        {
            printf("Diagonal element is zero. Exiting program.\n");
            exit(0);
        }
        for (j = 0; j < n; j++)
        {
            if (j > i)
            {
                fac = matrix[j][i] / matrix[i][i];
                // row transform
                for (k = 0; k < n + 1; k++)
                {
                    matrix[j][k] = matrix[j][k] - (fac * matrix[i][k]);
                }
            }
        }
    }
    printMatrix(matrix, n, n + 1);
    // back substitution
    sol[n - 1] = matrix[n - 1][n] / matrix[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        sol[i] = matrix[i][n];
        for (j = i + 1; j < n; j++)
        {
            sol[i] -= matrix[i][j] * sol[j];
        }
        sol[i] /= matrix[i][i];
    }
    // print the solution
    printf("Solution is : \n");
    for (i = 0; i < n; i++)
    {
        printf("x%d = %.2f\n", i + 1, sol[i]);
    }
    return 0;
}
