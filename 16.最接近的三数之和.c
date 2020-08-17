/*
 * @lc app=leetcode.cn id=16 lang=c
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.76%)
 * Likes:    547
 * Dislikes: 0
 * Total Accepted:    144.4K
 * Total Submissions: 315.5K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：nums = [-1,2,1,-4], target = 1
 * 输出：2
 * 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 10^3
 * -10^3 <= nums[i] <= 10^3
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start


int comp(const void *a,const void *b) {
    return *(int*)a - *(int*)b;
}
int threeSumClosest(int* nums, int numsSize, int target){
    qsort(nums, numsSize, sizeof(int), comp);
    int min = INT_MAX;
    for (int i = 0;i < numsSize;i++) {
        int j = i + 1;
        int k = numsSize - 1;
        int curMin = INT_MAX;
        int subTarget = target - nums[i];
        while(j<k) {
            int sum = nums[j] + nums[k];
            if (abs(curMin) > abs(sum - subTarget))
                curMin = sum - subTarget;
            if (sum > subTarget)
                k--;
            else if (sum < subTarget)
                j++;
            else
                return target;
        }
        if (abs(curMin) < abs(min))
            min = curMin;
    }
    return target + min;
}
// @lc code=end

