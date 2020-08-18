/*
 * @lc app=leetcode.cn id=283 lang=c
 *
 * [283] 移动零
 *
 * https://leetcode-cn.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (62.02%)
 * Likes:    700
 * Dislikes: 0
 * Total Accepted:    192.9K
 * Total Submissions: 311K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 * 
 * 说明:
 * 
 * 
 * 必须在原数组上操作，不能拷贝额外的数组。
 * 尽量减少操作次数。
 * 
 * 
 */

// @lc code=start


void moveZeroes(int* nums, int numsSize){
	if(numsSize==0) return;
	int* des=(int*)malloc(numsSize*sizeof(int));
	memset(des,0,sizeof(int)*numsSize);
	int j=0;
	for(int i=0;i<numsSize;i++){
		if(nums[i]!=0)
			des[j++]=nums[i];
	}
	memcpy(nums,des,sizeof(int)*numsSize);
	free(des);
}
// @lc code=end

