#include <stdio.h>
#include <stdbool.h>
#include "go.c"

//2869
// int main() {
//     int array[] = {3,1,5,4,2};
//     int result = minOperations(array, sizeof(array)/sizeof(array[0]), 2);
//     printf("%d", result);
//     return 0;
// }

//2760
// int main() {
//     int nums[] = {3,2,5,4};
//     int threshold = 5;
//     int result = longestAlternatingSubarray(nums, sizeof(nums)/sizeof(nums[0]), threshold);
//     printf("%d", result);
//     return 0;
// }


//2784
// int main() {
//     int nums[] = {2, 1, 3};
//     bool result = isGood(nums, sizeof(nums) / sizeof(nums[0]));
//     if (result) {
//         printf("数组 nums 是有效的！\n");
//     } else {
//         printf("数组 nums 无效。\n");
//     }
    
//     return 0;
// }


//2894
// int main() {
//     int n = 10;
//     int m = 3;
//     int result = differenceOfSums(n, m);
//     printf("结果是：%d\n", result);
//     return 0;
// }

//2600
// 调用 kItemsWithMaximumSum 函数并传入 numOnes = 3, numZeros = 2, numNegOnes = 0, k = 2
// int main() {
//     int result = kItemsWithMaximumSum(3, 2, 0, 2);
//     printf("调用 kItemsWithMaximumSum 函数的结果: %d\n", result);
//     return 0;
// }

// int main() {
//     int nums[] = {4, 5, 2, 1};
//     int queries[] = {3, 10, 21};
//     int n = sizeof(nums) / sizeof(nums[0]);
//     int m = sizeof(queries) / sizeof(queries[0]);

//     int results[m];

//     for (int i = 0; i < m; i++) {
//         int max_sum = 0;
//         int max_count = 0;

//         for (int j = 0; j < n; j++) {
//             int total_sum = 0;
//             int count = 0;

//             for (int k = j; k < n; k++) {
//                 total_sum += nums[k];
//                 count++;

//                 if (total_sum <= queries[i] && count > max_count) {
//                     max_sum = total_sum;
//                     max_count = count;
//                 }
//             }
//         }

//         results[i] = max_count;
//     }

//     printf("[");
//     for (int i = 0; i < m - 1; i++) {
//         printf("%d, ", results[i]);
//     }
//     printf("%d", results[m - 1]);
//     printf("]");

//     return 0;
// }

//62
// int main() {
//     // 测试示例1：m = 3, n = 7
//     printf("示例1：m = 3, n = 7\n结果：%d\n\n", uniquePaths(3, 7));
    
//     // 测试示例2：m = 3, n = 2
//     printf("示例2：m = 3, n = 2\n结果：%d\n\n", uniquePaths(3, 2));
    
//     // 测试示例3：m = 7, n = 3
//     printf("示例3：m = 7, n = 3\n结果：%d\n\n", uniquePaths(7, 3));
    
//     // 测试示例4：m = 3, n = 3
//     printf("示例4：m = 3, n = 3\n结果：%d\n", uniquePaths(3, 3));
    
//     return 0;
// }

//64
// void main()
// {
//     // ... existing code ...

//     // New code to call minPathSum
//     int m = 3, n = 3;
//     int** grid = (int**)malloc(m * sizeof(int*));
//     for (int i = 0; i < m; i++) {
//         grid[i] = (int*)malloc(n * sizeof(int));
//     }
    
//     // Initialize the grid
//     int tempGrid[3][3] = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             grid[i][j] = tempGrid[i][j];
//         }
//     }

//     int result = minPathSum(grid, m, &n);
//     printf("最小路径和是：%d\n", result);

//     // Free allocated memory
//     for (int i = 0; i < m; i++) {
//         free(grid[i]);
//     }
//     free(grid);

//     // ... existing code ...
// }
// 63.不同路径 II
// int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize);
// int main() {
//     // 创建一个障碍物网格
//     int m = 3, n = 3;
    
//     int** obstacleGrid = (int**)malloc(m * sizeof(int*));
//     for (int i = 0; i < m; i++) {
//         obstacleGrid[i] = (int*)malloc(n * sizeof(int));
//     }

//     // 初始化网格
//     int tempGrid[3][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             obstacleGrid[i][j] = tempGrid[i][j];
//         }
//     }

//     // 调用函数并输出结果
//     int result = uniquePathsWithObstacles(obstacleGrid, m, &n);
//     printf("不同路径的数量是：%d\n", result);

//     // 释放分配的内存
//     for (int i = 0; i < m; i++) {
//         free(obstacleGrid[i]);
//     }
//     free(obstacleGrid);

//     return 0;
// }
//---------------------------
// 120. 三角形最小路径和
// int main() {
//     // 创建一个整数类型的三角形数组
//     int triangleSize = 4;
//     int triangleColSize[] = {1, 2, 3, 4};   // 创建了一个三角形的列大小数组
//     int** triangle = (int**)malloc(triangleSize * sizeof(int*));
//     for (int i = 0; i < triangleSize; i++) {
//         triangle[i] = (int*)malloc((i + 1) * sizeof(int));
//     }

//     // 初始化三角形
//     int tempTriangle[4][4] = {
//         {2, 0, 0, 0},
//         {3, 4, 0, 0},
//         {6, 5, 7, 0},
//         {4, 1, 8, 3}
//     };
//     for (int i = 0; i < triangleSize; i++) {
//         for (int j = 0; j <= i; j++) {
//             triangle[i][j] = tempTriangle[i][j];
//         }
//     }

//     // 调用函数并输出结果
//     int result = minimumTotal(triangle, triangleSize, triangleColSize);
//     printf("三角形的最小路径和是：%d\n", result);

//     // 释放分配的内存
//     for (int i = 0; i < triangleSize; i++) {
//         free(triangle[i]);
//     }
//     free(triangle);

//     return 0;
// }
//-------------------------
// 931. 下降路径最小和
// int main() {
//     // 创建一个矩阵
//     int matrixSize = 3;
//     int matrixColSize[] = {3, 3, 3};
//     int** matrix = (int**)malloc(matrixSize * sizeof(int*));
//     for (int i = 0; i < matrixSize; i++) {
//         matrix[i] = (int*)malloc(matrixColSize[i] * sizeof(int));
//     }

//     // 初始化矩阵
//     int tempMatrix[3][3] = {
//         {2, 1, 3},
//         {6, 5, 4},
//         {7, 8, 9}
//     };
//     for (int i = 0; i < matrixSize; i++) {
//         for (int j = 0; j < matrixColSize[i]; j++) {
//             matrix[i][j] = tempMatrix[i][j];
//         }
//     }

//     // 调用函数并输出结果
//     int result = minFallingPathSum(matrix, matrixSize, matrixColSize);
//     printf("下降路径的最小和是：%d\n", result);

//     // 释放分配的内存
//     for (int i = 0; i < matrixSize; i++) {
//         free(matrix[i]);
//     }
//     free(matrix);

//     return 0;
// }
//--------------------------
int main() {
    //创建一个矩阵
    int matrixSize = 4;
    int matrixColSize[] = {5,5,5,5};
    int** matrix = (int**)malloc(matrixSize*sizeof(int*));
    for (int i = 0;i<matrixSize;i++){
        matrix[i] = (int*)malloc(matrixColSize[i]*sizeof(int));
    }


    int tempMatrix[4][5] = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            matrix[i][j] = tempMatrix[i][j];
        }
    }


    int result = maximalSquare(matrix, matrixSize, matrixColSize);
    printf("最大正方形的面积是：%d\n",result);
    return 0;
}
