/*
 * @lc app=leetcode.cn id=290 lang=c
 *
 * [290] 单词规律
 *
 * https://leetcode-cn.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (43.32%)
 * Likes:    181
 * Dislikes: 0
 * Total Accepted:    29.5K
 * Total Submissions: 68.2K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
 * 
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
 * 
 * 示例1:
 * 
 * 输入: pattern = "abba", str = "dog cat cat dog"
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:pattern = "abba", str = "dog cat cat fish"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: pattern = "aaaa", str = "dog cat cat dog"
 * 输出: false
 * 
 * 示例 4:
 * 
 * 输入: pattern = "abba", str = "dog dog dog dog"
 * 输出: false
 * 
 * 说明:
 * 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
 * 
 */

// @lc code=start


bool wordPattern(char * pattern, char * str){
    char **hash = (char **)malloc(26 * sizeof(char*));
    for (int i = 0; i < 26; ++i){
        hash[i] = (char*)malloc(64 * sizeof(char));
        memset(hash[i], 0, 64 * sizeof(char));
    }
    int len = strlen(pattern);
    for (int i = 0; i < len; ++i){
        char *p = str;
        while (p && *p != 0 && *p != ' ') ++p;
        if (' ' == *p) *p++ = 0;
        if (strlen(str) == 0)
            return false;
        int pos = pattern[i] - 'a';
        if (strlen(hash[pos]) == 0){
            for (int j = 0; j < 26; ++j)
                if (j != pos && strlen(hash[j]) > 0
                    && strcmp(hash[j], str) == 0)
                        return false;
            strcpy(hash[pos], str);
        }
        else if (strcmp(hash[pos], str) != 0)
            return false;
        str = p;        
    }
    if (strlen(str) > 0)
        return false;
    return true;
}


// @lc code=end

