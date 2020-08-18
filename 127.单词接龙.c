/*
 * @lc app=leetcode.cn id=127 lang=c
 *
 * [127] 单词接龙
 *
 * https://leetcode-cn.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (43.22%)
 * Likes:    404
 * Dislikes: 0
 * Total Accepted:    55.1K
 * Total Submissions: 127.6K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord
 * 的最短转换序列的长度。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回 0。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出: 5
 * 
 * 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * ⁠    返回它的长度 5。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: 0
 * 
 * 解释: endWord "cog" 不在字典中，所以无法进行转换。
 * 
 */

// @lc code=start


#define MAX_LEN 100000
#define WORD_LEN 100
typedef struct {
    char word[WORD_LEN];
    unsigned short step[2];
} Node;

typedef struct {
    Node node[MAX_LEN];
    int front;
    int rear;
    int size;
} Queue;

Queue g_queue1;
Queue g_queue2;

#define INT_MAX 0x7fffffff
#define NEXT_MAX 26

typedef struct tagNode {
    int pass;
    int end;
    int step[2];
    struct tagNode *next[NEXT_MAX];
} TNode, *Trie;

#define LETTER_MAX 26
char *g_word = NULL;
char *g_endWord = NULL;
Trie g_root = NULL;
int g_wordLen = 0;

#define ENTER_QUEUE(queue, dir, w, s) \
do { \
    int len; \
    char *tmp = (queue)->node[(queue)->rear].word; \
    len = strlen(w); \
    (void)strncpy(tmp, w, len); \
    tmp[len] = '\0'; \
    (queue)->node[(queue)->rear].step[dir] = s; \
    (queue)->rear++; \
} while (0)
Trie CreateNode(void){
    int len;
    Trie node = NULL;
    len = sizeof(TNode);
    node = (Trie)malloc(len);
    if (node == NULL)
        return NULL;
    memset(node, 0, len);
    node->step[0] = INT_MAX;
    node->step[1] = INT_MAX;
    return node;
}
void Insert(Trie root, char *s){
    Trie t = root;
    int len = 0;
    int idx;
    Trie tmp = NULL;
    len = strlen(s);
    for (int i = 0; i < len; i++) {
        idx = s[i] - 'a';
        if (t->next[idx] == NULL) {
            tmp = CreateNode();
            if (tmp == NULL)
                return;
            t->next[idx] = tmp;
        }
        t = t->next[idx];
        t->pass++;
    }
    t->end++;
    return;
}
void CreateDict(char ** words, int wordsSize){
    Trie root = NULL;
    root = CreateNode();
    for (int i = 0; i < wordsSize; ++i)
       Insert(root, words[i]);
    Insert(root, g_word);
    g_root = root;
    return;
}
Trie HasAnswer(char * word, bool dir){
    int i;
    int idx;
    Trie t = g_root;
    if (t == NULL)
        return NULL;
    for (i = 0; i < g_wordLen; ++i) {
        idx = word[i] - 'a';
        if (t->next[idx] == NULL)
            return NULL;
        t = t->next[idx];      
    }
    if (t->end <= 0)
        return NULL;
    return t;
}
void InitQueue(char * beginWord, char * endWord){
    g_queue1.front = 0;
    g_queue1.rear = 0;
    g_queue2.front = 0;
    g_queue2.rear = 0;
    ENTER_QUEUE(&g_queue1, 0, beginWord, 0);
    ENTER_QUEUE(&g_queue2, 1, endWord, 0);
    return;
}
char g_letter[] = "abcdefghijklmnopqrstuvwxyz";
int Bfs(bool dir, Queue *queue, char **wordList){
    char *word = NULL;
    int step, i, j;
    int size = queue->rear - queue->front;
    Trie t = NULL;
    Trie t2 = NULL;
    while (size-- > 0) {
        word = queue->node[queue->front].word;
        step = queue->node[queue->front].step[dir];
        queue->front++;  
        ++step;
        for (i = 0; i < g_wordLen; i++) {
            char tmp = word[i];
            for (j = 0; j < LETTER_MAX; j++) {    
                if (tmp ==g_letter[j])
                    continue;
                word[i] = g_letter[j];           
                t = HasAnswer(word, dir);
                if (t == NULL)
                    continue;
                if (t->step[dir] != INT_MAX)
                    continue;
                if (t->step[!dir] != INT_MAX)
                    return step + t->step[!dir] + 1;
                t->step[dir] = step;
                ENTER_QUEUE(queue, dir, word, step);           
            }
            word[i] = tmp;
        }
    }   
    return 0;
}
int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    int i;
    int step;
    char mask[WORD_LEN] = {0};
    Trie t = NULL;
    if (strcmp(beginWord, endWord) == 0)
        return 1;
    g_wordLen = strlen(beginWord);
        g_word = beginWord;
    g_endWord = endWord; 
    CreateDict(wordList, wordListSize);
    t = HasAnswer(beginWord, 0);
    if (t == NULL)
        return 0;
    t->step[0] = 0;
    t = HasAnswer(endWord, 1);
    if (t == NULL)
        return 0;
    t->step[1] = 0;
    InitQueue(beginWord, endWord);
    bool dir = false;
    while ((g_queue1.front != g_queue1.rear) && (g_queue2.front != g_queue2.rear)) {
        step = Bfs(dir, &g_queue1, wordList);
        if (step)
            return step;
        step = Bfs(!dir, &g_queue2, wordList);
        if (step)
            return step;
    }
    return 0;
}


// @lc code=end

