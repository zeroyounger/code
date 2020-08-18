/*
 * @lc app=leetcode.cn id=149 lang=c
 *
 * [149] 直线上最多的点数
 *
 * https://leetcode-cn.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (22.93%)
 * Likes:    173
 * Dislikes: 0
 * Total Accepted:    15K
 * Total Submissions: 65.3K
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * 给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。
 * 
 * 示例 1:
 * 
 * 输入: [[1,1],[2,2],[3,3]]
 * 输出: 3
 * 解释:
 * ^
 * |
 * |        o
 * |     o
 * |  o  
 * +------------->
 * 0  1  2  3  4
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * 输出: 4
 * 解释:
 * ^
 * |
 * |  o
 * |     o        o
 * |        o
 * |  o        o
 * +------------------->
 * 0  1  2  3  4  5  6
 * 
 */

// @lc code=start


int maxPoints(int** points, int pointsSize, int* pointsColSize){
    if(pointsSize<3) return pointsSize;
    int maxp=2;
    for(int i=0;i<pointsSize-1;i++){
        for(int j=i+1;j<pointsSize;j++){
            int temp=0;
            long x1=points[i][0],y1=points[i][1];
            long x2=points[j][0],y2=points[j][1];
            if(x1==x2&&y1==y2){
                x2++;
                y2++;
            }
            for(int k=0;k<pointsSize;k++){
                long x=points[k][0];
                long y=points[k][1];
                if(((y-y1)*(x2-x1)==(x-x1)*(y2-y1))){
                    temp++;
                }
            }
            maxp=fmax(maxp,temp);
        }
    }
    return maxp;
}
// @lc code=end

