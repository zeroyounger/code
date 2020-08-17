/*
 * @lc app=leetcode.cn id=381 lang=c
 *
 * [381] O(1) 时间插入、删除和获取随机元素 - 允许重复
 *
 * https://leetcode-cn.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/
 *
 * algorithms
 * Hard (38.00%)
 * Likes:    73
 * Dislikes: 0
 * Total Accepted:    3.3K
 * Total Submissions: 8.8K
 * Testcase Example:  '["RandomizedCollection","insert","insert","insert","getRandom","remove","getRandom"]\n' +
  '[[],[1],[1],[2],[],[1],[]]'
 *
 * 设计一个支持在平均 时间复杂度 O(1) 下， 执行以下操作的数据结构。
 * 
 * 注意: 允许出现重复元素。
 * 
 * 
 * insert(val)：向集合中插入元素 val。
 * remove(val)：当 val 存在时，从集合中移除一个 val。
 * getRandom：从现有集合中随机获取一个元素。每个元素被返回的概率应该与其在集合中的数量呈线性相关。
 * 
 * 
 * 示例:
 * 
 * // 初始化一个空的集合。
 * RandomizedCollection collection = new RandomizedCollection();
 * 
 * // 向集合中插入 1 。返回 true 表示集合不包含 1 。
 * collection.insert(1);
 * 
 * // 向集合中插入另一个 1 。返回 false 表示集合包含 1 。集合现在包含 [1,1] 。
 * collection.insert(1);
 * 
 * // 向集合中插入 2 ，返回 true 。集合现在包含 [1,1,2] 。
 * collection.insert(2);
 * 
 * // getRandom 应当有 2/3 的概率返回 1 ，1/3 的概率返回 2 。
 * collection.getRandom();
 * 
 * // 从集合中删除 1 ，返回 true 。集合现在包含 [1,2] 。
 * collection.remove(1);
 * 
 * // getRandom 应有相同概率返回 1 和 2 。
 * collection.getRandom();
 * 
 * 
 */

// @lc code=start



typedef struct {

} RandomizedCollection;

/** Initialize your data structure here. */

RandomizedCollection* randomizedCollectionCreate() {

}

/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
bool randomizedCollectionInsert(RandomizedCollection* obj, int val) {

}

/** Removes a value from the collection. Returns true if the collection contained the specified element. */
bool randomizedCollectionRemove(RandomizedCollection* obj, int val) {

}

/** Get a random element from the collection. */
int randomizedCollectionGetRandom(RandomizedCollection* obj) {

}

void randomizedCollectionFree(RandomizedCollection* obj) {

}

/**
 * Your RandomizedCollection struct will be instantiated and called as such:
 * RandomizedCollection* obj = randomizedCollectionCreate();
 * bool param_1 = randomizedCollectionInsert(obj, val);
 
 * bool param_2 = randomizedCollectionRemove(obj, val);
 
 * int param_3 = randomizedCollectionGetRandom(obj);
 
 * randomizedCollectionFree(obj);
*/
// @lc code=end

