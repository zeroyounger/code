/*
 * @lc app=leetcode.cn id=139 lang=c
 *
 * [139] 单词拆分
 *
 * https://leetcode-cn.com/problems/word-break/description/
 *
 * algorithms
 * Medium (47.32%)
 * Likes:    628
 * Dislikes: 0
 * Total Accepted:    84.2K
 * Total Submissions: 177.9K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
 * 
 * 说明：
 * 
 * 
 * 拆分时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 * 
 * 
 * 示例 1：
 * 
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
 * 
 * 
 * 示例 2：
 * 
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
 * 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 * 
 * 
 */

// @lc code=start


#define MAX_LENGTH  (200)
bool isStrEndWith(char *s, int endIdx, char *wordDict, int *left){
    int wordDictLen = strlen(wordDict);
    int stringLen = endIdx + 1;
    if (wordDictLen > stringLen) {
        return false;
    }
    if (strncmp(s + stringLen - wordDictLen, wordDict, wordDictLen) == 0) {
        *left = stringLen - wordDictLen;
        return true;
    }
    return false;
}

bool wordBreak(char *s, char **wordDict, int wordDictSize){
    bool dp[MAX_LENGTH] = {0};   //从index 0到i的字符串能否拆分为多个单词    
    int stringLen = strlen(s);
    if (stringLen > MAX_LENGTH) {
        printf("ERROR: stringLen %d\n", stringLen);
        return;
    }
    for (int i = 0; i < stringLen; i++) {
        //和字典中的每个单词比较，判断是否以它结尾
        for (int j = 0; j < wordDictSize; j++) {
            int left = 0;
            if (isStrEndWith(s, i, wordDict[j], &left)) {                
                if (left == 0 || dp[left - 1] == 1) {
                    //没有剩余字符，或者剩余的字符串也可以拆分，则退出
                    dp[i] = 1;
                    break;
                }
            }
        }
    }
    return dp[stringLen - 1];
}
// @lc code=end

