/*
 * @lc app=leetcode.cn id=62 lang=c
 *
 * [62] 不同路径
 *
 * https://leetcode-cn.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (61.78%)
 * Likes:    644
 * Dislikes: 0
 * Total Accepted:    135.4K
 * Total Submissions: 219.1K
 * Testcase Example:  '3\n2'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 问总共有多少条不同的路径？
 * 
 * 
 * 
 * 例如，上图是一个7 x 3 的网格。有多少可能的路径？
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: m = 3, n = 2
 * 输出: 3
 * 解释:
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向右 -> 向下
 * 2. 向右 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向右
 * 
 * 
 * 示例 2:
 * 
 * 输入: m = 7, n = 3
 * 输出: 28
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= m, n <= 100
 * 题目数据保证答案小于等于 2 * 10 ^ 9
 * 
 * 
 */

// @lc code=start


int uniquePaths(int m, int n){
    if (m <= 0 || n <= 0) return 0;
    int*  table = malloc(m*n*sizeof(int));
    for (int i = 0; i < m; i++)
        table[i] = 1;
    for (int i = 0; i < n; i++)
        table[m*i] = 1;
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            table[j*m+i] = table[(j-1)*m+i] + table[j*m+i-1];
    return table[m*n-1];
}

// @lc code=end

