/*
 * @lc app=leetcode.cn id=45 lang=c
 *
 * [45] 跳跃游戏 II
 *
 * https://leetcode-cn.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (37.34%)
 * Likes:    664
 * Dislikes: 0
 * Total Accepted:    76.7K
 * Total Submissions: 205.4K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给定一个非负整数数组，你最初位于数组的第一个位置。
 * 
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
 * 
 * 示例:
 * 
 * 输入: [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。
 * 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 * 
 * 
 * 说明:
 * 
 * 假设你总是可以到达数组的最后一个位置。
 * 
 */

// @lc code=start


int jump(int* nums, int numsSize){
    if (NULL == nums || 0 == numsSize)
    {
        return 0;
    }

    int slow = 0;
    int fast = 0;
    int max = 0;
    int step = 0;

    for (slow = 0; slow <= fast; )
    {
        if (fast >= numsSize - 1)
        {
            return step;
        }

        for (; slow <= fast; slow++)
        {
            max = max > slow + nums[slow] ? max : slow + nums[slow];
        }

        fast = max;
        step++;
    }

    return 0;
}

// @lc code=end

