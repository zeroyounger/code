/*
 * @lc app=leetcode.cn id=33 lang=c
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (38.50%)
 * Likes:    887
 * Dislikes: 0
 * Total Accepted:    159.2K
 * Total Submissions: 413.5K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 * 
 * 你可以假设数组中不存在重复的元素。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 示例 1:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 3
 * 输出: -1
 * 
 */

// @lc code=start


int search(int* nums, int numsSize, int target){
	int retval = -1;
	int left = 0;
	int right = numsSize - 1;
	int median = (left + right) / 2;
	while(left <= right){
		if(nums[median] == target){
			retval = median;
			break;
		}else{
			if(nums[median] >= nums[left]){
				if(target >= nums[left] && target < nums[median])
					right = median - 1;
				else
					left = median + 1;
			}else{
				if(target > nums[median] && target <= nums[right])
					left = median + 1;
				else
					right = median - 1;
			}
            median = (left + right) / 2;
		}
	}
	return retval;
}
// @lc code=end

