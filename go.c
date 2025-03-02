#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>     //qsort

//62
int uniquePaths(int m, int n) {
    // 创建一个二维数组来存储到达每个位置的路径数
    long long dp[100][100] = {0};
    
    // 初始化第一行和第一列
    for(int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    for(int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }
    
    // 计算每个格子的路径数
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    return (int)dp[m-1][n-1];   ////从0开始储存，因此是调用dp[m-1][n-1];
}


void hello(){
printf("Hello World\n");
}

//2869
int minOperations(int* nums, int numsSize, int k){
     int i,hash[100000]={0},t=0;
     int count=k;//count计数器初始值为k
     for(i=numsSize-1;i>=0;i--){//从后往前依次遍历
         
         ++hash[nums[i]];//将遍历到的元素放进hash中
         if(nums[i]>=1&&nums[i]<=k&&hash[nums[i]]<2){
             count--;//如果数组中的元素在区间内并且hash中＜2则减一
         }
         if(count==0) return numsSize-i;
         
     }
     return numsSize-i;//如果count不为0则返回-1
}
// --------------------------------------------------------------------------
// 2760
bool isSatisfied(int* nums, int l, int r, int threshold){
    if(nums[l] % 2 != 0){
        return false;
    }
    for(int i = l; i <= r; i++){
        if(nums[i] > threshold || (i < r && nums[i] % 2 == nums[i + 1] % 2)){
            return false;
        }
    }
    return true;
}
int longestAlternatingSubarray(int* nums, int numsSize, int threshold){
    int res = 0;
    for(int l = 0; l < numsSize; l++){
        for(int r = l; r < numsSize; r++){
            if(isSatisfied(nums, l, r, threshold) && res < r - l + 1){
                res = r - l + 1;
            }
        }
    }
    return res;
}
// --------------------------------------------------------------------------
//2784
int cmp(const void*a, const void *b)
{
    return *(int *)b - *(int *)a;
}
bool isGood(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    if (nums[0] + 1 == numsSize && nums[0] == nums[1]) {
        for (int i = 1; i < numsSize - 1; i++) {
            if (nums[i] != nums[i + 1] + 1) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}
// --------------------------------------------------------------------------
//2894
int differenceOfSums(int n, int m) {
  return (n * (n + 1) >> 1) - n / m * (n / m + 1) * m;
}

// 2600
int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k){
    if (k <= numOnes)
        return k;
    else if(k <= (numOnes+numZeros))
        return numOnes;
    return numOnes-(k-numOnes-numZeros);
}

//--------------------------------------------------------------------------
//2331
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool evaluateTree(struct TreeNode* root){   //传入struct TreeNode类型的root[]       root = [2,1,3,null,null,0,1]
    if (root == NULL) {
        return false; // 或者根据具体需求返回其他值
    }
    if(root -> val == 1){
        return true;
    }
    else if(root -> val == 0){
        return false;
    }
    bool left = evaluateTree(root -> left);     //函数_1 left == 1->函数_2 val == 1 return true
    bool right = evaluateTree(root -> right);   //函数_1 right == 3->函数_2 val == 3 return false->函数_3 val== 3  (left == 0->函数_5 val == 0 return false) (right == 1->函数_6 val == 1 return true) return 0
    if(root -> val == 2){           //函数_1 return 1
        return left || right;
    }
    else if(root -> val == 3){
        return left && right;
    }
    return false;
}

// -------------------------------------------------------------------------
//2389

int* answerQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    for(int i = 1; i < numsSize; i++)
        nums[i] += nums[i - 1];

    for(int i = 0; i < queriesSize; i++){
        int left = 0, right = numsSize - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] <= queries[i])
                left = mid + 1;
            else
                right = mid - 1;
        }
        queries[i] = left;
    }
    *returnSize = queriesSize;

    return queries;
}

// -------------------------------------------------------------------------

//64
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = *gridColSize;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue; // Skip the starting cell
            if (i == 0) grid[i][j] += grid[i][j - 1]; // First row
            else if (j == 0) grid[i][j] += grid[i - 1][j]; // First column
            else grid[i][j] += (grid[i - 1][j] < grid[i][j - 1]) ? grid[i - 1][j] : grid[i][j - 1]; // Min path sum
        }
    }
    return grid[m - 1][n - 1]; // Return the bottom-right cell
}
//hand write
// for (int i=0;i<m;i++){
//     for(int j=0;j<n;j++){
//         if(i==0&&j==0) continue;
//         if(i=0) grid[i][j] += grid[i][j-1];
//         else if(j=0) grid[i][j] += grid[i-1][j];
//         else grid[i][j] += (grid[i-1][j] < grid[i][j-1])? grid[i-1][j]:gird[j][i-1];
//     }
//     return grid[m-1][n-1];
// }

// 63.不同路径 II
// go.c
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize;
    int n = *obstacleGridColSize;

    // 如果起点或终点有障碍物，返回0
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
        return 0;
    }

    // 创建一个二维数组来存储路径数
    int dp[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0; // 有障碍物的格子路径数为0
            } else if (i == 0 && j == 0) {
                dp[i][j] = 1; // 起点路径数为1
            } else {
                dp[i][j] = 0;
                if (i > 0) dp[i][j] += dp[i - 1][j]; // 从上方到达
                if (j > 0) dp[i][j] += dp[i][j - 1]; // 从左方到达
            }
        }
    }
    return dp[m - 1][n - 1]; // 返回右下角的路径数
}
//hand write
// if (obstacleGrid[0][0] == 1 && obstacleGrid[m-1][n-1] == 0){ return 0;}

// int dp[m][n];
// for(int i=0;i<m){
//     for (int j=0;j<n;j++){
//         if (obstacleGrid[i][j] == 1){
//             dp[i][j] = 0;
//         }
//         if (i==0&&j==0){
//             dp[i][j]=1;
//         }else{
//             dp[i][j]=0;
//             if(i>0) dp[i][j] += dp[i-1][j];
//             if(j>0) dp[i][j] += dp[i][j-1];
//         }
//     }
// }
// return dp[i-1][j-1];
//----------------------------
// 120. 三角形最小路径和
// go.c
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    // 从倒数第二行开始向上计算最小路径和
    for (int i = triangleSize - 2; i >= 0; i--) {   //这里的标都是从0开始的，因此是triangleSize减2
        for (int j = 0; j < triangleColSize[i]; j++) {  //对于这行的triangleColSize进行遍历，该行每个triangle[i][j]都更新一遍
            // 更新当前节点的值为其下方相邻节点的最小路径和
            triangle[i][j] += (triangle[i + 1][j] < triangle[i + 1][j + 1]) ? triangle[i + 1][j] : triangle[i + 1][j + 1];
        }
    }
    return triangle[0][0]; // 返回顶端的最小路径和
}
//-----------------------------
//931. 下降路径最小和
// go.c
#include <math.h>
int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;

    // 从倒数第二行开始向上计算最小下降路径和
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            // 更新当前元素的值为其下方相邻元素的最小路径和
            int down = matrix[i + 1][j]; // 正下方
            int downLeft = (j > 0) ? matrix[i + 1][j - 1] : INT_MAX; // 左下方
            int downRight = (j < matrixColSize[i + 1] - 1) ? matrix[i + 1][j + 1] : INT_MAX; // 右下方

            matrix[i][j] += fmin(down, fmin(downLeft, downRight));
        }
    }

    // 找到第一行中的最小值
    int minPathSum = matrix[0][0];
    for (int j = 1; j < matrixColSize[0]; j++) {
        if (matrix[0][j] < minPathSum) {
            minPathSum = matrix[0][j];
        }
    }

    // int findMin(int arr[], int size) {
    // int min = arr[0]; // 假设第一个元素是最小值
    // for (int i = 1; i < size; i++) {
    //     if (arr[i] < min) {
    //         min = arr[i]; // 更新最小值
    //     }
    // }
    // return min; // 返回最小值
    // }
    
    return minPathSum; // 返回最小下降路径和

}
//--------------------------
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int maximalSquare(int** matrix, int matrixSize, int* matrixColSize) {
        int n = matrixSize;
        int m = matrixColSize[0];
        int dp[n][m];
        int ans = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
               if(matrix[i][j]=='1'){
                dp[i][j] = 1;
                if(i>0&&j>0){
                dp[i][j] += min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
               }
               ans = max(ans,dp[i][j]);
            }else{
                dp[i][j] = 0;
               }
        }
    }
    return ans*ans;
}
// 在 C++ 中，max 和 min 函数是标准库的一部分，可以直接使用，而在 C 语言中，虽然也有类似的功能，但需要注意以下几点：
// C 语言中的 max 和 min
// 没有内置的 max 和 min 函数：C 语言标准库没有提供 max 和 min 函数。你需要自己定义这些函数，或者使用宏来实现。
// 自定义 max 和 min 函数：你可以在 C 语言中自定义这两个函数。