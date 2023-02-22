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
            printf("%3.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void main(){
    int n=3,i,j,k;
    float m[3][MAX_SIZE+1],fac,sol[MAX_SIZE] ;// {{5,1,8,-5},{9,4,8,-6},{5,8,9,-1}},fac,sol[MAX_SIZE];
    //m = {{1,2,3,6},{4,5,6,15},{4,8,12,24}};
    printf("Enter number of equations : ");
    scanf("%d",&n);
    printf("Enter the augmented matrix row wise:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            printf("Enter element of row %d and col %d: ", i + 1, j + 1);
            scanf("%f", &m[i][j]);
        }
    }
    printMatrix(m,n,n+1);
    for(i=0;i<n;i++){
        if (m[i][i] == 0)
        {
            printf("Diagonal element is zero. Exiting program.\n");
            exit(0);
        }
        for(j=0;j<n;j++){
            if(j>i){
                fac=m[j][i]/m[i][i];
                for(k=0;k<n+1;k++){
                    m[j][k]=m[j][k]-fac*m[i][k];
                }
            }
        }
    }
    printMatrix(m,n,n+1);
    sol[n - 1] = m[n - 1][n] / m[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        sol[i] = m[i][n];
        for (j = i + 1; j < n; j++)
        {
            sol[i] -= m[i][j] * sol[j];
        }
        sol[i] /= m[i][i];
    }
    // print the solution
    printf("Solution is : \n");
    for (i = 0; i < n; i++)
    {
        printf("x%d = %.2f\n", i + 1, sol[i]);
    }
}