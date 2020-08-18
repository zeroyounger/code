/*
 * @lc app=leetcode.cn id=140 lang=c
 *
 * [140] 单词拆分 II
 *
 * https://leetcode-cn.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (38.51%)
 * Likes:    216
 * Dislikes: 0
 * Total Accepted:    19.9K
 * Total Submissions: 51.6K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典
 * wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。
 * 
 * 说明：
 * 
 * 
 * 分隔时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 * 
 * 
 * 示例 1：
 * 
 * 输入:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * 输出:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * 示例 2：
 * 
 * 输入:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * 输出:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * 解释: 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出:
 * []
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct list RESULTLIST;
struct list {
    char *str;
    RESULTLIST *next;
};
int g_resultCnt = 0;
RESULTLIST* g_resultList = NULL;
RESULTLIST* g_resultListTmp = NULL;
void RefreshResult (char * s, char ** wordDict, int wordDictSize, int index, int depth, int* resultIndex, char* flag) {
    int i;
    char tmpFlag = 0;
    RESULTLIST* listTmp = NULL;
    if (1 != flag[index]) {
        return;
    }
    if (index == strlen(s)) { // 查找完一个场景，输出结果
        g_resultCnt++;
        listTmp = (RESULTLIST*)malloc(sizeof(RESULTLIST));
        listTmp->str = (char*)malloc(strlen(s) + depth + 2);
        memset(listTmp->str, 0, (strlen(s) + depth + 2));
        for (i = 0; i < depth; i++) {
            strcat(listTmp->str, wordDict[resultIndex[i]]);
            if (i == (depth - 1)) {
                break;
            }
            strcat(listTmp->str, " ");
        }
        g_resultListTmp->next = listTmp;
        g_resultListTmp = listTmp;
        return;
    }
    depth++;
    for (i = 0; i < wordDictSize; i++) {
        if (strncmp(s + index, wordDict[i], strlen(wordDict[i])) == 0) {
                resultIndex[depth - 1] = i; // 存储字典下标
                RefreshResult (s, wordDict, wordDictSize, index + strlen(wordDict[i]), depth, resultIndex, flag); 
                tmpFlag = 1;
            }
    }
    if (0 == tmpFlag) {
        return;
    }
}
char ** wordBreak(char * s, char ** wordDict, int wordDictSize, int* returnSize){
    char* flagAray = NULL;
    int* resultIndex = NULL;
    int lenOfStr;
    int i, j;
    char** retResult = NULL;
    RESULTLIST* tmpList = NULL;
    *returnSize = 0;
    lenOfStr = strlen(s) + 1;
    flagAray = (char*)malloc(lenOfStr * sizeof(char));
    memset(flagAray, 0, (lenOfStr * sizeof(char)));
    resultIndex = (int*)malloc(lenOfStr * sizeof(int));
    memset(resultIndex, 0, lenOfStr * sizeof(int));
    flagAray[lenOfStr - 1] = 1;
    for (i = lenOfStr - 1; i >= 0; i--) {
        if (flagAray[i] != 1)
            continue;
        for (j = 0; j < wordDictSize; j++) {
            if (i < strlen(wordDict[j]))
                continue;
            if (strncmp(s + i - strlen(wordDict[j]), wordDict[j], strlen(wordDict[j])) == 0)
                flagAray[i - strlen(wordDict[j])] = 1;
        }
    }
    if (flagAray[0] != 1) {
        *returnSize = 0;
        return NULL;
    }
    g_resultList = (RESULTLIST*)malloc(sizeof(RESULTLIST));
    g_resultListTmp = g_resultList;
    g_resultCnt = 0;
    RefreshResult (s, wordDict, wordDictSize, 0, 0, resultIndex, flagAray);
    g_resultListTmp = g_resultList;
    retResult = (char**)malloc(g_resultCnt * sizeof(char*));
    for (i = 0; i < g_resultCnt; i++) {
        tmpList = g_resultListTmp->next;
        retResult[i] = tmpList->str;
        free(g_resultListTmp);
        g_resultListTmp = tmpList;
    }
    *returnSize = g_resultCnt;
    return retResult;
}
// @lc code=end

