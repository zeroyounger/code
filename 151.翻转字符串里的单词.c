/*
 * @lc app=leetcode.cn id=151 lang=c
 *
 * [151] 翻转字符串里的单词
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (43.06%)
 * Likes:    207
 * Dislikes: 0
 * Total Accepted:    89K
 * Total Submissions: 206.7K
 * Testcase Example:  '"the sky is blue"'
 *
 * 给定一个字符串，逐个翻转字符串中的每个单词。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: "the sky is blue"
 * 输出: "blue is sky the"
 * 
 * 
 * 示例 2：
 * 
 * 输入: "  hello world!  "
 * 输出: "world! hello"
 * 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 
 * 
 * 示例 3：
 * 
 * 输入: "a good   example"
 * 输出: "example good a"
 * 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 * 
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 无空格字符构成一个单词。
 * 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。
 * 
 */

// @lc code=start


char * reverseWords(char * s){
    int i = 0;
    int len = 0;
    int subLen = 0;
    int begin = 0;
    int end = 0;
    bool first = false;
    char *ret = NULL;
    char *temp = NULL;
    len = strlen(s);
    ret = (char *)malloc(sizeof(char) * (len+1));
    temp = ret;
    for (i = len -1; i >=0; i--){
        if (s[i] != ' ' && first == false){
            end = i+1;
            first = true;
        }else if (s[i] == ' ' && end > 0){
            begin = i+1;
            first = false;
        }
        if (s[i] != ' ' && i == 0){
            begin = 0;
            first = false;
        }
        if (first == false && end - begin > 0){
            subLen = end - begin;
            if (temp != ret){
                *temp++= ' ';
            }
            memcpy(temp, &s[begin], subLen);
            temp += subLen;
            end = 0;
            begin = 0;
        }
    }
    *temp++= '\0';
    return ret;
}

// @lc code=end

