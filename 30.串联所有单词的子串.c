/*
 * @lc app=leetcode.cn id=30 lang=c
 *
 * [30] 串联所有单词的子串
 *
 * https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (31.54%)
 * Likes:    320
 * Dislikes: 0
 * Total Accepted:    41.5K
 * Total Submissions: 131.5K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
 * 
 * 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * 输出：[0,9]
 * 解释：
 * 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
 * 输出的顺序不重要, [9,0] 也是有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * 输出：[]
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
    static int out[1000];
    int cnt = 0;
    if (s == NULL || wordsSize == NULL || wordsSize <= 0) {
        *returnSize = cnt;
        return out;
    }
    int slen = strlen(s);
    int wlen = strlen(words[0]);
    int sum = 0;
    for (int i = 0; i < wordsSize; i++)
        sum += words[i][0];
    for (int i = 0; i < wlen; i++) {
        int times = (slen - i) / wlen - wordsSize + 1;
        int tmp = 0;
        for (int j = 0; j < (wordsSize - 1); j++)
            tmp += s[i + j * wlen];
        for (int j = 0; j < times; j++) {
            tmp += s[i + (j + wordsSize - 1) * wlen];
            if (tmp == sum) {
                char flags[wordsSize];
                memset(flags, 0, wordsSize);
                for (int m = 0; m < wordsSize; m++) {
                    for (int n = 0; n < wordsSize; n++) {
                        if ((flags[n] == 0) && (strncmp(&s[i + (j + m) * wlen], words[n], wlen) == 0)) {
                            flags[n] = 1;
                            break;
                        }
                    }
                }
                int ccc = 0;
                for (int m = 0; m < wordsSize; m++)
                    if (flags[m] == 1)
                        ccc++;
                if (ccc == wordsSize)
                    out[cnt++] = i + j * wlen;
            }
            tmp -= s[i + j * wlen];
        }
    }
    *returnSize = cnt;
    return out;
}


// @lc code=end

