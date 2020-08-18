/*
 * @lc app=leetcode.cn id=179 lang=c
 *
 * [179] 最大数
 *
 * https://leetcode-cn.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (36.84%)
 * Likes:    354
 * Dislikes: 0
 * Total Accepted:    38.7K
 * Total Submissions: 105.1K
 * Testcase Example:  '[10,2]'
 *
 * 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
 * 
 * 示例 1:
 * 
 * 输入: [10,2]
 * 输出: 210
 * 
 * 示例 2:
 * 
 * 输入: [3,30,34,5,9]
 * 输出: 9534330
 * 
 * 说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 * 
 */

// @lc code=start


int cmp(const void * a, const void* b);
char str[1600] = {0};
char * largestNumber(int* nums, int numsSize){
    *str = '\0';
    char tmp[20] = {0};
    qsort(nums, numsSize, sizeof(int), cmp);
    if (nums[numsSize-1] == 0) return "0";
    while(numsSize != 0) {
        sprintf(tmp, "%d", nums[--numsSize]);
        strcat(str, tmp);
    }
    return str;
}
int cmp(const void * a, const void* b){
    int num_a, num_b;
    char *pa;
    char *pb;
    char arr_a[20] = {0};
    char arr_b[20] = {0};
    num_a = *(int *)a;
    num_b = *(int *)b;
    do {
        arr_a[++arr_a[0]] = num_a % 10;
        num_a /= 10;
    }while (num_a != 0);
    do {
        arr_b[++arr_b[0]] = num_b % 10;
        num_b /= 10;
    }while (num_b != 0);
    pa = &arr_a[arr_a[0]];
    pb = &arr_b[arr_b[0]];
    while (*(pa) == *(pb)) {
        pa--;
        pb--;
        if (pa == arr_a) pa = &arr_b[arr_b[0]];
        if (pb == arr_b) pb = &arr_a[arr_a[0]];
        if (pa == arr_b) break;
    }
    if (pa == arr_b) return 0;
    if (*pa < *pb) return -1;
    else return 1;
}


// @lc code=end

