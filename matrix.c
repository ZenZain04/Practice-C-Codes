#include <stdio.h>

// Define maximum size for the matrices
#define MAX 10

void multiplyMatrices(int firstMatrix[MAX][MAX], int secondMatrix[MAX][MAX], int resultMatrix[MAX][MAX],
                      int rowFirst, int colFirst, int rowSecond, int colSecond);



int main() {
    int rowFirst, colFirst, rowSecond, colSecond;
    int firstMatrix[MAX][MAX], secondMatrix[MAX][MAX], resultMatrix[MAX][MAX];

    // Input dimensions of the first matrix
    printf("Enter the number of rows and columns of the first matrix (max %d): ", MAX);
    scanf("%d %d", &rowFirst, &colFirst);

    // Input dimensions of the second matrix
    printf("Enter the number of rows and columns of the second matrix (max %d): ", MAX);
    scanf("%d %d", &rowSecond, &colSecond);

    // Ensure the matrices can be multiplied
    if (colFirst != rowSecond) {
        printf("Error! column of first matrix is not equal to row of second.\n");
        return -1;
    }

    // Input elements of the first matrix
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < rowFirst; ++i) {
        for (int j = 0; j < colFirst; ++j) {
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    // Input elements of the second matrix
    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < rowSecond; ++i) {
        for (int j = 0; j < colSecond; ++j) {
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    // Perform matrix multiplication
    multiplyMatrices(firstMatrix, secondMatrix, resultMatrix, rowFirst, colFirst, rowSecond, colSecond);

    // Output the result
    printf("The resulting matrix is:\n");
    for (int i = 0; i < rowFirst; ++i) {
        for (int j = 0; j < colSecond; ++j) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
void multiplyMatrices(int (*firstMatrix)[10], int (*secondMatrix)[10], int (*resultMatrix)[10], int rowFirst, int colFirst,
                 int rowSecond, int colSecond) {

    for (int i = 0; i < rowFirst; ++i) {
        for (int j = 0; j < colSecond; ++j) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < colFirst; ++k) {
                resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}
