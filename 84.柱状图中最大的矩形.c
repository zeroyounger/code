/*
 * @lc app=leetcode.cn id=84 lang=c
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (41.41%)
 * Likes:    850
 * Dislikes: 0
 * Total Accepted:    79.7K
 * Total Submissions: 192.4K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 
 * 
 * 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
 * 
 * 
 * 
 * 
 * 
 * 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [2,1,5,6,2,3]
 * 输出: 10
 * 
 */

// @lc code=start


int largestRectangleArea(int* heights, int heightsSize){
    int *stack = (int *) malloc(sizeof(int) * heightsSize);
    int area = 0;
    int top = 0;
    if (heightsSize == 0)
        return 0;
    if (heightsSize == 1)
        return heights[0];
    for (int i = 0; i < heightsSize; i ++) {
        if ((top == 0) || (heights[i] >= heights[stack[top - 1]])){
            stack[top ++] = i;
        } else {
            do{
                top --;
                int height = heights[stack[top]];
                int width = (top == 0) ? i : (i - stack[top -1] -1);
                int tmp_area = height * width;
                if (tmp_area > area) {
                    area = tmp_area;
                }
            }while((top != 0) && ((heights[i] < heights[stack[top - 1]])));
            stack[top ++] = i;
        }
    }
    while(top != 0) {
        top --;
        int height = heights[stack[top]];
        int width = (top == 0) ? heightsSize : (heightsSize - stack[top -1] -1);
        int tmp_area = height * width;
        if (tmp_area > area)
            area = tmp_area;
    }
    return area;
}


// @lc code=end

