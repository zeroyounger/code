/*
 * @lc app=leetcode.cn id=126 lang=c
 *
 * [126] 单词接龙 II
 *
 * https://leetcode-cn.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (38.55%)
 * Likes:    307
 * Dislikes: 0
 * Total Accepted:    22.4K
 * Total Submissions: 58.1K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord
 * 的最短转换序列。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换后得到的单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回一个空列表。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: []
 * 
 * 解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct HashNode {
    char* s;  
    int index;
    struct HashNode* next;
}HashNode;
typedef struct {
    int size;
    HashNode** table;
}HashTable;
unsigned int RSHash(char* str, unsigned int len) {
   unsigned int b    = 378551;
   unsigned int a    = 63689;
   unsigned int hash = 0;
   unsigned int i    = 0;
   for(i = 0; i < len; str++, i++) {
      hash = hash * a + (*str);
      a    = a * b;
   } 
   return hash;
}
HashTable* createHashTable(int size) {
    HashTable* hash = malloc(sizeof(HashTable));
    hash->size = size;
    hash->table = malloc(sizeof(HashNode*)*size);
    memset(hash->table, 0, sizeof(HashNode*)*size);
    return hash;
}
void addHash(HashTable* hash, char* s, int idx, int len) {
    unsigned int num = RSHash(s, len);
    int index = num%hash->size;
    HashNode* node = malloc(sizeof(HashNode));
    node->s = s;
    node->index = idx;
    node->next = hash->table[index];
    hash->table[index] = node;
}
int searchHashIndex(HashTable* hash, char* s, int len) {
    unsigned int num = RSHash(s, len);
    int index = num%hash->size;
    HashNode* node = hash->table[index];
    while (node != NULL) {
        if (memcmp(node->s, s, len) == 0) return node->index;
        node = node->next;
    }
    return -1;
}
void backtrack(char**** res, int* memSize, int* returnSize, int* path, int index, bool** edges, int* reverseDist, char ** wordList, int wordListSize, char * beginWord, int endPos, int destPathLen) {
    int last = path[index-1];
    if (index == destPathLen) {
        char** aPath = malloc(sizeof(char*)*(destPathLen+1));
        aPath[0] = beginWord;
        for (int i = 1; i < destPathLen; i++) {
            aPath[i] = wordList[path[i]];
        }
        aPath[destPathLen] = wordList[endPos];
        if (*returnSize == *memSize) {
            *memSize = 2**memSize;
            *res = realloc(*res, (*memSize)*sizeof(char**));
        }
        (*res)[*returnSize] = aPath;
        *returnSize = *returnSize+1;
        return;
    }
    for (int i = 0; i < wordListSize; i++) {
        if (edges[i][last] && reverseDist[i] == index) {
            path[index] = i;
            backtrack(res, memSize, returnSize, path, index+1, edges, reverseDist, wordList, wordListSize, beginWord, endPos, destPathLen);
        }
    } 
}
void reverseDistance(bool** edges, int wordListSize, int endPos, int* dist, int* reverseDist) {
    int* queue = malloc(sizeof(int)*(wordListSize+1));
    int front = -1, pos = -1;
    queue[++pos] = endPos;    
    while(front != pos) {
        int p = queue[++front];
        int d = dist[p];
        if (d == 1) break;
        for (int i = 0; i < wordListSize; i++) {
            if (edges[i][p] && dist[i] == d-1 && reverseDist[i] == 0) {
                queue[++pos] = i;
                reverseDist[i] = d-1;
            }
        }
    }
}
bool** createEdges(int wordListSize) {
    bool** edges = malloc(sizeof(bool*)*(wordListSize+1));
    for (int i = 0; i < wordListSize+1; i++) {
        edges[i] = malloc(sizeof(bool)*(wordListSize+1));
        memset(edges[i], 0, sizeof(bool)*(wordListSize+1));
    }
    return edges;
}

int fillNodeDistEdge(int* dist, int idx, int d, char* tmp, int wordLen, HashTable* hashTable,bool** edges, int endPos, int* queue, int* queuePos) {
    for (int i = 0; i < wordLen; i++) {
        char tmpc = tmp[i];
        for (char c = 'a'; c < tmpc; c++) {
            tmp[i] = c;
            int pos = searchHashIndex(hashTable, tmp, wordLen);
            if (pos >= 0) {
                edges[idx][pos] = true;
                edges[pos][idx] = true;
                if (dist[pos] == 0) {
                    dist[pos] = d;
                    *queuePos = *queuePos+1;
                    queue[*queuePos] = pos;
                    if (pos == endPos) {
                        tmp[i] = tmpc;
                        return d;
                    }
                }
            }
        }
        for (char c = tmpc+1; c <= 'z'; c++) {
            tmp[i] = c;
            int pos = searchHashIndex(hashTable, tmp, wordLen);
            if (pos >= 0) {
                edges[idx][pos] = true;
                edges[pos][idx] = true;
                if (dist[pos] == 0) {
                    dist[pos] = d;
                    *queuePos = *queuePos+1;
                    queue[*queuePos] = pos;
                    if (pos == endPos) {
                        tmp[i] = tmpc;
                        return d;
                    }
                }
            }
        }
        tmp[i] = tmpc;
    }
    return -1;
}
int getEndDist(HashTable* hashTable, bool** edges, char * beginWord, int endPos, int* dist, char ** wordList, int wordListSize, int wordLen) {    
    int* queue = malloc(sizeof(int)*(wordListSize+1));
    int front = -1, pos = -1;
    int p = wordListSize; 
    int d = 0;
    char* s = beginWord;
    char* tmp = s;
    int pathLen = wordListSize+1;
    int r = fillNodeDistEdge(dist, p, 1, tmp, wordLen, hashTable, edges, endPos, queue, &pos); 
    if (r < 0) {
         while(pos != front) {
            int p = queue[++front];
            int d = dist[p];
            if (d == pathLen) break;
             tmp = wordList[p];
            r = fillNodeDistEdge(dist, p, d+1, tmp, wordLen, hashTable, edges, endPos, queue, &pos); 
            if (r > 0) pathLen = r;
        }
    } else {
        pathLen = r;
    }
    return pathLen;
}
HashTable* createWordhashTable(char ** wordList, int wordListSize, int wordLen) {
    HashTable* hashTable = createHashTable(wordListSize*2);
    for (int i = 0; i < wordListSize; i++) {
        addHash(hashTable, wordList[i], i, wordLen);
    }
    return hashTable;
}
char *** findLadders(char * beginWord, char * endWord, char ** wordList, int wordListSize, int* returnSize, int** returnColumnSizes){
    if (wordList == NULL || wordListSize == 0) { *returnSize = 0; *returnColumnSizes = NULL; return NULL;}
    int wordLen = strlen(beginWord);
    HashTable* hashTable = createWordhashTable(wordList, wordListSize, wordLen);
    int pos = searchHashIndex(hashTable, endWord, wordLen);
    if (pos < 0) { *returnSize = 0; *returnColumnSizes = NULL; return NULL;}
    bool** edges = createEdges(wordListSize);   
    int* dist = malloc(sizeof(int)*(wordListSize+1));
    memset(dist, 0, sizeof(int)*(wordListSize+1));
    int shortestPath = getEndDist(hashTable, edges, beginWord, pos, dist,  wordList, wordListSize, wordLen);
    if (shortestPath > wordListSize) { *returnSize = 0; *returnColumnSizes = NULL; return NULL;}
    int* reverseDist = malloc(sizeof(int)*(wordListSize+1));
    memset(reverseDist, 0, sizeof(int)*(wordListSize+1));
    reverseDistance(edges, wordListSize, pos, dist, reverseDist);
    int memSize = 1024;
    char*** result = malloc(sizeof(char**)*memSize);
    *returnSize = 0;
    int* path = malloc(sizeof(int)*(shortestPath+1));
    path[0] = wordListSize;
    backtrack(&result, &memSize, returnSize, path, 1, edges, reverseDist, wordList, wordListSize, beginWord, pos, shortestPath);
    *returnColumnSizes = malloc(sizeof(int)**returnSize);
    for (int i = 0; i < *returnSize; i++) (*returnColumnSizes)[i] = shortestPath+1;
    return result;
}


// @lc code=end

