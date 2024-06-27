#include <stdio.h>
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
int main() {
    int result = kItemsWithMaximumSum(3, 2, 0, 2);
    printf("调用 kItemsWithMaximumSum 函数的结果: %d\n", result);
    return 0;
}