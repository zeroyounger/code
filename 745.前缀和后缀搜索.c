/*
 * @lc app=leetcode.cn id=745 lang=c
 *
 * [745] 前缀和后缀搜索
 *
 * https://leetcode-cn.com/problems/prefix-and-suffix-search/description/
 *
 * algorithms
 * Hard (33.28%)
 * Likes:    41
 * Dislikes: 0
 * Total Accepted:    1.4K
 * Total Submissions: 4.3K
 * Testcase Example:  '["WordFilter","f"]\n[[["apple"]],["a","e"]]'
 *
 * 给定多个 words，words[i] 的权重为 i 。
 * 
 * 设计一个类 WordFilter 实现函数WordFilter.f(String prefix, String suffix)。这个函数将返回具有前缀
 * prefix 和后缀suffix 的词的最大权重。如果没有这样的词，返回 -1。
 * 
 * 例子:
 * 
 * 
 * 输入:
 * WordFilter(["apple"])
 * WordFilter.f("a", "e") // 返回 0
 * WordFilter.f("b", "") // 返回 -1
 * 
 * 
 * 注意:
 * 
 * 
 * words的长度在[1, 15000]之间。
 * 对于每个测试用例，最多会有words.length次对WordFilter.f的调用。
 * words[i]的长度在[1, 10]之间。
 * prefix, suffix的长度在[0, 10]之前。
 * words[i]和prefix, suffix只包含小写字母。
 * 
 * 
 */

// @lc code=start



typedef struct {
    
} WordFilter;


WordFilter* wordFilterCreate(char ** words, int wordsSize) {
    
}

int wordFilterF(WordFilter* obj, char * prefix, char * suffix) {
  
}

void wordFilterFree(WordFilter* obj) {
    
}

/**
 * Your WordFilter struct will be instantiated and called as such:
 * WordFilter* obj = wordFilterCreate(words, wordsSize);
 * int param_1 = wordFilterF(obj, prefix, suffix);
 
 * wordFilterFree(obj);
*/
// @lc code=end

