/*
 * @lc app=leetcode.cn id=17 lang=c
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (54.30%)
 * Likes:    832
 * Dislikes: 0
 * Total Accepted:    145K
 * Total Submissions: 267.1K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_NUM 1000
char* g_phoneKey[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void dfs(char *digits, char **res, int *returnSize, int index, char *temp, int num){
    for (int j = 0; j < strlen(g_phoneKey[num - 2]); j++) {
        temp[index] = g_phoneKey[num -2][j];
        if (index == strlen(digits) - 1) {
            res[*returnSize] = (char*)malloc(sizeof(char) * (strlen(digits) + 1));
            strcpy(res[*returnSize], temp);
            (*returnSize)++;
            continue;
        }
        dfs(digits, res, returnSize, index + 1, temp, digits[index + 1] - '0');
    }
}

char ** letterCombinations(char * digits, int* returnSize){
    *returnSize = 0;
    char **res = (char**)malloc(sizeof(char*) * MAX_NUM);
    if (strcmp(digits, "") == 0)
        return res;
    char *temp = (char*)malloc(sizeof(char) * (strlen(digits) + 1));
    memset(temp, 0, sizeof(char) * (strlen(digits) + 1));
    int num = digits[0] - '0';
    dfs(digits, res, returnSize, 0, temp, num);
    return res;
}
// @lc code=end

