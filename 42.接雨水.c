/*
 * @lc app=leetcode.cn id=42 lang=c
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (52.22%)
 * Likes:    1558
 * Dislikes: 0
 * Total Accepted:    135.4K
 * Total Submissions: 259.3K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 * 
 */

// @lc code=start


int trap(int* height, int heightSize){
    int *stack = (int *)malloc((heightSize + 1) * sizeof(int));
    int top = 0;
    int distance = 0;
    int bounded_height = 0;
    int result = 0;
    for (int i = 0; i < heightSize; i++) {
        while (top != 0 && height[i] > height[stack[top]]) {
            top--;
            if (top == 0)
                break;
            distance = i - stack[top] - 1;
            bounded_height = fmin(height[i], height[stack[top]]) - height[stack[top + 1]];
            result += distance * bounded_height;
        }
        stack[++top] = i;
    }
    free(stack);
    return result;
}


// @lc code=end

