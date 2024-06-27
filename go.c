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