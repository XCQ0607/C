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
// int main() {
//     int result = kItemsWithMaximumSum(3, 2, 0, 2);
//     printf("调用 kItemsWithMaximumSum 函数的结果: %d\n", result);
//     return 0;
// }

#include <stdio.h>
#include "go.c"
#include <stdbool.h>

int main() {
    int nums[] = {4, 5, 2, 1};
    int queries[] = {3, 10, 21};
    int n = sizeof(nums) / sizeof(nums[0]);
    int m = sizeof(queries) / sizeof(queries[0]);

    int results[m];

    for (int i = 0; i < m; i++) {
        int max_sum = 0;
        int max_count = 0;

        for (int j = 0; j < n; j++) {
            int total_sum = 0;
            int count = 0;

            for (int k = j; k < n; k++) {
                total_sum += nums[k];
                count++;

                if (total_sum <= queries[i] && count > max_count) {
                    max_sum = total_sum;
                    max_count = count;
                }
            }
        }

        results[i] = max_count;
    }

    printf("[");
    for (int i = 0; i < m - 1; i++) {
        printf("%d, ", results[i]);
    }
    printf("%d", results[m - 1]);
    printf("]");

    return 0;
}
