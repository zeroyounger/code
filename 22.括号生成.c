/*
 * @lc app=leetcode.cn id=22 lang=c
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (76.01%)
 * Likes:    1244
 * Dislikes: 0
 * Total Accepted:    164.7K
 * Total Submissions: 216.6K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：n = 3
 * 输出：[
 * ⁠      "((()))",
 * ⁠      "(()())",
 * ⁠      "(())()",
 * ⁠      "()(())",
 * ⁠      "()()()"
 * ⁠    ]
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs(char** result, char* str, int left, int right, int n, int* returnSize) {
	if ((left + right) == 2 * n) {
		result[*returnSize] = (char*)malloc(sizeof(char*) * (2 * n + 1));
		memcpy(result[*returnSize], str, 2 * n);
		result[*returnSize][2 * n] = '\0';
		*returnSize = *returnSize + 1;
		return;
	}
	if (left < n) {
		strcat(str, "(");
		dfs(result, str, left + 1, right, n, returnSize);
		str[left + right] = '\0';
	}
	if (left > right) {
		strcat(str, ")");
		dfs(result, str, left, right + 1, n, returnSize);
		str[left + right] = '\0';
	}
}
char** generateParenthesis(int n, int* returnSize) {
	char** result = (char**)malloc(sizeof(char*) * 1430);
	char* outStr = (char*)malloc(sizeof(char) * (n * 2 + 1));
	*returnSize = 0;
	*outStr = 0;
	dfs(result, outStr, 0, 0, n, returnSize);
	return result;
}


// @lc code=end

