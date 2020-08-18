/*
 * @lc app=leetcode.cn id=223 lang=c
 *
 * [223] 矩形面积
 *
 * https://leetcode-cn.com/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (43.60%)
 * Likes:    84
 * Dislikes: 0
 * Total Accepted:    11.4K
 * Total Submissions: 26.1K
 * Testcase Example:  '-3\n0\n3\n4\n0\n-1\n9\n2'
 *
 * 在二维平面上计算出两个由直线构成的矩形重叠后形成的总面积。
 * 
 * 每个矩形由其左下顶点和右上顶点坐标表示，如图所示。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: -3, 0, 3, 4, 0, -1, 9, 2
 * 输出: 45
 * 
 * 说明: 假设矩形面积不会超出 int 的范围。
 * 
 */

// @lc code=start


int computeArea(int A, int B, int C, int D, int E, int F, int G, int H){
    int area1 = (D - B) * (C - A);
    int area2 = (G - E) * (H - F);
    int up = fmin(D, H);
    int dow = fmax(B, F);
    int left = fmax(A, E);
    int right = fmin(C, G); 
    if ((up < dow) || (left > right))
        return area1 + area2;
    return area1 - (up - dow) * (right - left) + area2;
}

// @lc code=end

