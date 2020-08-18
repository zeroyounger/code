/*
 * @lc app=leetcode.cn id=168 lang=c
 *
 * [168] Excel表列名称
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (38.22%)
 * Likes:    251
 * Dislikes: 0
 * Total Accepted:    32.7K
 * Total Submissions: 85.6K
 * Testcase Example:  '1'
 *
 * 给定一个正整数，返回它在 Excel 表中相对应的列名称。
 * 
 * 例如，
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "A"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 28
 * 输出: "AB"
 * 
 * 
 * 示例 3:
 * 
 * 输入: 701
 * 输出: "ZY"
 * 
 * 
 */

// @lc code=start


char * convertToTitle(int n){
    int len = 0, tmp = n;
    while (tmp){
        len++;
        tmp = (tmp - 1) / 26;
    }
    char *res = (char*)malloc(len + 1);
    tmp = n;
    res[len] = 0;
    while (len--){
        res[len] = (tmp - 1) % 26 + 'A';
        tmp = (tmp - 1) / 26;
    }
    return res;
}



// @lc code=end

