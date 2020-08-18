/*
 * @lc app=leetcode.cn id=152 lang=c
 *
 * [152] 乘积最大子数组
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (40.15%)
 * Likes:    714
 * Dislikes: 0
 * Total Accepted:    87.2K
 * Total Submissions: 217.1K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 * 
 */

// @lc code=start


int maxProduct(int* nums, int numsSize){
	int i, j, sum, max;
	i = 0; sum = 1; max = INT_MIN;
	for(j = 0; j <= numsSize; j++){
		if(j == numsSize || nums[j] == 0){
			max = fmax(max, j < numsSize ? 0 : max);
			while(sum < 0 && i < j - 1){
				sum /= nums[i++];
				max = fmax(max, sum);
			}
			sum = 1;
			i = j + 1;
		}else{
			sum *= nums[j];
			max = fmax(max, sum);
		}
	}	
	return max;
}
// @lc code=end

