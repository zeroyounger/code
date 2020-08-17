/*
 * @lc app=leetcode.cn id=49 lang=c
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (63.06%)
 * Likes:    434
 * Dislikes: 0
 * Total Accepted:    97.3K
 * Total Submissions: 154.3K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct {
    unsigned long long key;
    int index;
} StrkeyInfo;
int comp(StrkeyInfo *a, StrkeyInfo *b){
    return (a->key > b->key) ? 1 : -1;
}
char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes){
    char ***returnStr;
    int i, j; 
    int columnSize = 1;
    int size = 0;
    StrkeyInfo *keyInfo;
    int prime[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
                      47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101
                    };
    returnStr = (char ***)malloc(strsSize * sizeof(char **));
    *returnColumnSizes = (int *)malloc(strsSize * sizeof(int));
    keyInfo = (StrkeyInfo *)malloc(strsSize * sizeof(StrkeyInfo));
    for (i = 0; i < strsSize; i++) {
        keyInfo[i].key = 1;
        keyInfo[i].index = i;
        for (j = 0; j < strlen(strs[i]); j++)
            keyInfo[i].key *= prime[strs[i][j] - 'a'];
    }
    qsort(keyInfo, strsSize, sizeof(StrkeyInfo), comp);
    for (i = 1; i < strsSize; i++) {
        if (keyInfo[i - 1].key == keyInfo[i].key) {
            columnSize++;
        } else {
            returnStr[size] = (char **)malloc(columnSize * sizeof(char *));
            for (j = 0; j < columnSize; j++)
                returnStr[size][j] = strs[keyInfo[i + j - columnSize].index];
            (*returnColumnSizes)[size++] = columnSize;
            columnSize = 1;
        }
    }
    returnStr[size] = (char **)malloc(columnSize * sizeof(char *));
    for (j = 0; j < columnSize; j++)
        returnStr[size][j] = strs[keyInfo[i + j - columnSize].index];
    (*returnColumnSizes)[size++] = columnSize;
    *returnSize = size;
    free(keyInfo);
    return returnStr;
}


// @lc code=end

