/*
 * @lc app=leetcode.cn id=815 lang=c
 *
 * [815] 公交路线
 *
 * https://leetcode-cn.com/problems/bus-routes/description/
 *
 * algorithms
 * Hard (31.00%)
 * Likes:    61
 * Dislikes: 0
 * Total Accepted:    4.4K
 * Total Submissions: 14.1K
 * Testcase Example:  '[[1,2,7],[3,6,7]]\n1\n6'
 *
 * 我们有一系列公交路线。每一条路线 routes[i] 上都有一辆公交车在上面循环行驶。例如，有一条路线 routes[0] = [1, 5,
 * 7]，表示第一辆 (下标为0) 公交车会一直按照 1->5->7->1->5->7->1->... 的车站路线行驶。
 * 
 * 假设我们从 S 车站开始（初始时不在公交车上），要去往 T 站。 期间仅可乘坐公交车，求出最少乘坐的公交车数量。返回 -1
 * 表示不可能到达终点车站。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：
 * routes = [[1, 2, 7], [3, 6, 7]]
 * S = 1
 * T = 6
 * 输出：2
 * 解释：
 * 最优策略是先乘坐第一辆公交车到达车站 7, 然后换乘第二辆公交车到车站 6。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= routes.length <= 500.
 * 1 <= routes[i].length <= 10^5.
 * 0 <= routes[i][j] < 10 ^ 6.
 * 
 * 
 */

// @lc code=start


int numBusesToDestination(int** routes, int routesSize, int* routesColSize, int S, int T){

}


// @lc code=end

