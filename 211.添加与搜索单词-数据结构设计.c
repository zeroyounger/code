/*
 * @lc app=leetcode.cn id=211 lang=c
 *
 * [211] 添加与搜索单词 - 数据结构设计
 *
 * https://leetcode-cn.com/problems/design-add-and-search-words-data-structure/description/
 *
 * algorithms
 * Medium (46.06%)
 * Likes:    151
 * Dislikes: 0
 * Total Accepted:    14.5K
 * Total Submissions: 31.4K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n' +
  '[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * 如果数据结构中有任何与word匹配的字符串，则bool search（word）返回true，否则返回false。 单词可能包含点“。”
 * 点可以与任何字母匹配的地方。
 * 
 * 请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。
 * 
 * 实现词典类 WordDictionary ：
 * 
 * 
 * WordDictionary() 初始化词典对象
 * void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
 * bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。word 中可能包含一些
 * '.' ，每个 . 都可以表示任何一个字母。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：
 * 
 * ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
 * [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
 * 输出：
 * [null,null,null,null,false,true,true,true]
 * 
 * 解释：
 * WordDictionary wordDictionary = new WordDictionary();
 * wordDictionary.addWord("bad");
 * wordDictionary.addWord("dad");
 * wordDictionary.addWord("mad");
 * wordDictionary.search("pad"); // return False
 * wordDictionary.search("bad"); // return True
 * wordDictionary.search(".ad"); // return True
 * wordDictionary.search("b.."); // return True
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= word.length <= 500
 * addWord 中的 word 由小写英文字母组成
 * search 中的 word 由 '.' 或小写英文字母组成
 * 最调用多 50000 次 addWord 和 search
 * 
 * 
 */

// @lc code=start


#define WORD_NUM 26
typedef struct {
    int end;
    struct WordDictionary *childList[WORD_NUM];
} WordDictionary;
WordDictionary* wordDictionaryCreate() {
    int i;
    WordDictionary *root = NULL;
    root = (WordDictionary *)malloc(sizeof(WordDictionary));
    if (root == NULL)
        return NULL;
    for (i = 0; i < WORD_NUM; i++)
        root->childList[i] = NULL;
    root->end = 0;
    return root;
}
void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    char *p = word;
    WordDictionary *node = obj;
    while (*p != '\0') {
        if (node->childList[*p - 'a'] == NULL)
            node->childList[*p - 'a'] = wordDictionaryCreate();
        node = node->childList[*p - 'a'];
        p++;
    }
    node->end = 1;
}
bool wordDictionarySearch(WordDictionary* obj, char * word) {
    int i;
    int j;
    char *p = word;
    WordDictionary *node = obj;
    if (node == NULL)
        return false;
    while (*p != '\0' && node != NULL) {
        if (*p == '.') {
            for (i = 0; i < WORD_NUM; i++)
                if (wordDictionarySearch(node->childList[i], p + 1))
                    return true;
            return false;
        } else if (node->childList[*p - 'a'] == NULL) {
            return false;
        }
        node = node->childList[*p - 'a'];
        p++;
    }
    if (node != NULL && node->end == 1)
        return true;
    return false;
}
void wordDictionaryFree(WordDictionary* obj) {
    int i;
    if (obj == NULL)
        return;
    for (i = 0; i < WORD_NUM; i++) 
        wordDictionaryFree(obj->childList[i]);
    free(obj);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/
// @lc code=end

