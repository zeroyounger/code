/*
 * @lc app=leetcode.cn id=208 lang=c
 *
 * [208] 实现 Trie (前缀树)
 *
 * https://leetcode-cn.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (68.48%)
 * Likes:    380
 * Dislikes: 0
 * Total Accepted:    50.5K
 * Total Submissions: 73.7K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
 * 
 * 示例:
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // 返回 true
 * trie.search("app");     // 返回 false
 * trie.startsWith("app"); // 返回 true
 * trie.insert("app");   
 * trie.search("app");     // 返回 true
 * 
 * 说明:
 * 
 * 
 * 你可以假设所有的输入都是由小写字母 a-z 构成的。
 * 保证所有输入均为非空字符串。
 * 
 * 
 */

// @lc code=start


struct TrieNode{
    bool isEnd;
    struct TrieNode* map[26];
};
typedef struct TrieNode Trie;
Trie* trieCreate() {
    Trie* obj = (Trie*)malloc(sizeof(Trie));
    obj->isEnd = false;
    for(int i = 0; i < 26; i++)
	    obj->map[i] = NULL;
    return obj;
}
void trieInsert(Trie* obj, char * word) {
    while(*word){
        if(obj->map[*word-'a'] == NULL)
            obj->map[*word-'a'] = trieCreate();
        obj = obj->map[*word-'a'];
        word++;
    }
    obj->isEnd = true;
}
bool trieSearch(Trie* obj, char * word) {
    while(*word){
        if(obj->map[*word-'a'] == NULL)
            return false;
        obj = obj->map[*word-'a'];
        word++;
    }
    return obj->isEnd;
}
bool trieStartsWith(Trie* obj, char * prefix) {
    while(*prefix){
        if(obj->map[*prefix-'a'] == NULL)
	        return false;
        obj = obj->map[*prefix-'a'];
        prefix++;
    }
    return true;
}
void trieFree(Trie* obj) {
    for(int i = 0; i < 26; i++)
        if(obj->map[i] != NULL)
	        trieFree(obj->map[i]);
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
// @lc code=end

