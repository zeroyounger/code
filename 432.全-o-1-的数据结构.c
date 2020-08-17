/*
 * @lc app=leetcode.cn id=432 lang=c
 *
 * [432] 全 O(1) 的数据结构
 *
 * https://leetcode-cn.com/problems/all-oone-data-structure/description/
 *
 * algorithms
 * Hard (34.78%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    3.9K
 * Total Submissions: 11.3K
 * Testcase Example:  '["AllOne","getMaxKey","getMinKey"]\n[[],[],[]]'
 *
 * 请你实现一个数据结构支持以下操作：
 * 
 * 
 * Inc(key) - 插入一个新的值为 1 的 key。或者使一个存在的 key 增加一，保证 key 不为空字符串。
 * Dec(key) - 如果这个 key 的值是 1，那么把他从数据结构中移除掉。否则使一个存在的 key 值减一。如果这个 key
 * 不存在，这个函数不做任何事情。key 保证不为空字符串。
 * GetMaxKey() - 返回 key 中值最大的任意一个。如果没有元素存在，返回一个空字符串"" 。
 * GetMinKey() - 返回 key 中值最小的任意一个。如果没有元素存在，返回一个空字符串""。
 * 
 * 
 * 
 * 
 * 挑战：
 * 
 * 你能够以 O(1) 的时间复杂度实现所有操作吗？
 * 
 */

// @lc code=start



typedef struct {
    
} AllOne;

/** Initialize your data structure here. */

AllOne* allOneCreate() {
    
}

/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
void allOneInc(AllOne* obj, char * key) {
  
}

/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
void allOneDec(AllOne* obj, char * key) {
  
}

/** Returns one of the keys with maximal value. */
char * allOneGetMaxKey(AllOne* obj) {
  
}

/** Returns one of the keys with Minimal value. */
char * allOneGetMinKey(AllOne* obj) {
  
}

void allOneFree(AllOne* obj) {
    
}

/**
 * Your AllOne struct will be instantiated and called as such:
 * AllOne* obj = allOneCreate();
 * allOneInc(obj, key);
 
 * allOneDec(obj, key);
 
 * char * param_3 = allOneGetMaxKey(obj);
 
 * char * param_4 = allOneGetMinKey(obj);
 
 * allOneFree(obj);
*/
// @lc code=end

