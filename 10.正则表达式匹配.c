/*
 * @lc app=leetcode.cn id=10 lang=c
 *
 * [10] 正则表达式匹配
 *
 * https://leetcode-cn.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (30.19%)
 * Likes:    1458
 * Dislikes: 0
 * Total Accepted:    107.9K
 * Total Submissions: 357.5K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 * 
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 
 * 
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 * 
 * 说明:
 * 
 * 
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * s = "aa"
 * p = "a*"
 * 输出: true
 * 解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * s = "ab"
 * p = ".*"
 * 输出: true
 * 解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 * 
 * 
 * 示例 4:
 * 
 * 输入:
 * s = "aab"
 * p = "c*a*b"
 * 输出: true
 * 解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
 * 
 * 
 * 示例 5:
 * 
 * 输入:
 * s = "mississippi"
 * p = "mis*is*p*."
 * 输出: false
 * 
 */

// @lc code=start


bool isMatch(char * s, char * p){
	int s_len = strlen(s);
	int p_len = strlen(p);
	int i = 0;
	int j = 0;
	bool matrix[100][100] = { false };
	matrix[s_len][p_len] = true;
	for (i = s_len; i >= 0; --i) {
		for (j = p_len - 1; j >= 0; --j) {
			if (s[i] == p[j] || p[j] == '.') { // 'a-z' == 'a-z' || 'a-z' == '.'
				matrix[i][j] = matrix[i + 1][j + 1];
			}
			else if (p[j] == '*') {
				if (s[i] == p[j - 1] || p[j - 1] == '.') { // 'a-z' == '.*' 
					matrix[i][j - 1] = (matrix[i][j + 1] || matrix[i + 1][j - 1]);
				}
				else {
					matrix[i][j - 1] = matrix[i][j + 1];
				}
				--j;
			}
		}
	}
	return matrix[0][0];
}


// @lc code=end

