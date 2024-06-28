#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>     //qsort


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

