/*
 * @lc app=leetcode.cn id=260 lang=c
 *
 * [260] 只出现一次的数字 III
 *
 * https://leetcode-cn.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (73.39%)
 * Likes:    273
 * Dislikes: 0
 * Total Accepted:    27.7K
 * Total Submissions: 37.7K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * 给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。
 * 
 * 示例 :
 * 
 * 输入: [1,2,1,3,2,5]
 * 输出: [3,5]
 * 
 * 注意：
 * 
 * 
 * 结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。
 * 你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize){
    int i, num = 0;
    for(i = 0; i < numsSize; i++){
        num ^= nums[i];
    }
    num = num & (~num + 1);
    int* res = (int*)malloc(sizeof(int) * 2);
    res[0] = res[1] = 0;

    for(i = 0; i < numsSize; i++){
        if(nums[i] & num){
            res[0] ^= nums[i];
        }else{
	    res[1] ^= nums[i];
	    }
    }
    *returnSize = 2;
    return res;
}

// @lc code=end

