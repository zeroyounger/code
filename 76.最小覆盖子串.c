/*
 * @lc app=leetcode.cn id=76 lang=c
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (38.69%)
 * Likes:    700
 * Dislikes: 0
 * Total Accepted:    71.6K
 * Total Submissions: 185.1K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 S、一个字符串 T 。请你设计一种算法，可以在 O(n) 的时间复杂度内，从字符串 S 里面找出：包含 T 所有字符的最小子串。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：S = "ADOBECODEBANC", T = "ABC"
 * 输出："BANC"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 如果 S 中不存这样的子串，则返回空字符串 ""。
 * 如果 S 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 */

// @lc code=start


#define LEN  128
char* minWindow(char* s, char* t){
    int counter[LEN] = {0};
    int start=0, end=0, tLen=strlen(t), sLen=strlen(s);
    int minStart=0, minLen=INT_MAX;
    for(int i = 0; i < LEN; i++) counter[i] = -sLen; //distinguish the letter in and not in t;
    for(int i = 0; t[i]; i++) counter[t[i]] = 0;
    for(int i = 0; t[i]; i++) counter[t[i]]++;
    while(end < sLen){
        if(counter[s[end]]-- > 0) tLen--;
        end++; //move to the next character;
        while(tLen == 0){
            if(end-start < minLen) //collect the minimal only;
                minStart=start, minLen=end-start;
            counter[s[start]]++;
            if(counter[s[start]] > 0) tLen++; //if s[start] is in t;
            start++; //move forward by ignoring s[start];
        }
    }
    if(minLen != INT_MAX){
        char* t = (char*)malloc(sizeof(char)*(minLen+1));
        *t = '\0';
        strncat(t, s+minStart, minLen);
        return t;
    }
    return "";
}


// @lc code=end

