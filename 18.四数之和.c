/*
 * @lc app=leetcode.cn id=18 lang=c
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (38.26%)
 * Likes:    544
 * Dislikes: 0
 * Total Accepted:    99.7K
 * Total Submissions: 260.5K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp_int(const void* a, const void* b){
	return *(int *)a - *(int *)b;
}
void twosum(int* arr, int size, int a, int b, int twoTarget, int** res, int* pcount){
    if (2 * arr[0] > twoTarget || 2 * arr[size - 1] < twoTarget)return;
    int startIndex = 0;
    int endIndex = size - 1;
    while (startIndex < endIndex) {
        if (arr[startIndex] + arr[endIndex] < twoTarget) {
            startIndex++;
        }
        else if (arr[startIndex] + arr[endIndex] > twoTarget) {
            endIndex--;
        }
        else {
            if (startIndex > 0 && endIndex < size -1 && arr[startIndex] == arr[startIndex - 1] && arr[endIndex] == arr[endIndex+1]) {
                startIndex++;
                endIndex--;
            }
            else {
                res[*pcount] = (int*)malloc(sizeof(int) * 4);
                res[*pcount][0] = a;
                res[*pcount][1] = b;
                res[*pcount][2] = arr[startIndex];
                res[*pcount][3] = arr[endIndex];
                (*pcount)++;
                startIndex++;
                endIndex--;
            }
        }
    }
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    if (numsSize < 4) {
        *returnSize = 0;
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmp_int);
	int max = 8192;
	int** res = (int**)malloc(sizeof(int*) * max);
    int count = 0;
    for (int i = 0; i < numsSize -3; i++) {            
        if (4*nums[i] > target ||  4 * nums[numsSize - 1] < target) {break;}
        if (i>0 && nums[i] == nums[i-1]) {continue;}       
        for (int j = i + 1; j < numsSize - 2; j++) {                      
            if (3 * nums[j] > target - nums[i] || 3 * nums[numsSize - 1] < target - nums[i]) {break;}
            if (j > i + 1 && nums[j] == nums[j-1]) {continue;}
            twosum(nums + j + 1, numsSize - 1 - j, nums[i], nums[j], target - nums[i] - nums[j], res, &count);
        }
    }
	*returnColumnSizes = (int*)malloc(sizeof(int) * count);
	for (int i = 0; i < count; ++i)(*returnColumnSizes)[i] = 4;
	*returnSize = count;
	return res;
}


// @lc code=end

