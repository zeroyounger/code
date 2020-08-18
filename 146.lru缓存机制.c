/*
 * @lc app=leetcode.cn id=146 lang=c
 *
 * [146] LRU缓存机制
 *
 * https://leetcode-cn.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (50.43%)
 * Likes:    821
 * Dislikes: 0
 * Total Accepted:    90.8K
 * Total Submissions: 180K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
 * 
 * 获取数据 get(key) - 如果关键字 (key) 存在于缓存中，则获取关键字的值（总是正数），否则返回 -1。
 * 写入数据 put(key, value) -
 * 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字/值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 * 
 * 
 * 
 * 进阶:
 * 
 * 你是否可以在 O(1) 时间复杂度内完成这两种操作？
 * 
 * 
 * 
 * 示例:
 * 
 * LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // 返回  1
 * cache.put(3, 3);    // 该操作会使得关键字 2 作废
 * cache.get(2);       // 返回 -1 (未找到)
 * cache.put(4, 4);    // 该操作会使得关键字 1 作废
 * cache.get(1);       // 返回 -1 (未找到)
 * cache.get(3);       // 返回  3
 * cache.get(4);       // 返回  4
 * 
 * 
 */

// @lc code=start



typedef struct LRUItem {
    int key;
    int value;
    struct LRUItem *next;
    struct LRUItem *prev;

    struct LRUItem *hn;
    struct LRUItem *hp;
} LRUItem;

typedef struct {
    LRUItem *lru;
    LRUItem *data;
    LRUItem **hash;
    int capacity;
    int size;
} LRUCache;

static inline int hash_key(int k, int capacity) {
    return k % capacity;
}

LRUCache* lRUCacheCreate(int capacity) {
    if (capacity == 0)
        return NULL;

    LRUCache *obj = calloc(1, sizeof(LRUCache));
    obj->capacity = capacity;
    obj->data = calloc(capacity, sizeof(LRUItem));
    obj->hash = calloc(capacity, sizeof(void*));

    return obj;
}

static LRUItem *get(LRUCache *obj, int key) {
    int k = hash_key(key, obj->capacity);
    LRUItem *item = obj->hash[k];
    while (item) {
        if (item->key == key) {
            return item;
        }
        item = item->hn;
    }
    return item;
}

int lRUCacheGet(LRUCache* obj, int key) {
    if (obj == NULL)
        return -1;
    LRUItem *item = get(obj, key);

    if (item == NULL)
        return -1;

    if (obj->lru != item) {
        item->prev->next = item->next;
        item->next->prev = item->prev;
        item->next = obj->lru;
        item->prev = obj->lru->prev;
        item->prev->next = item;
        item->next->prev = item;
        obj->lru = item;
    }

    return item->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if (obj == NULL)
        return ;
    int k = hash_key(key, obj->capacity);
    LRUItem *item = get(obj, key);

    if (item) {
        item->value = value;
        if (obj->lru != item) {
            item->prev->next = item->next;
            item->next->prev = item->prev;
            item->next = obj->lru;
            item->prev = obj->lru->prev;
            item->prev->next = item;
            item->next->prev = item;
            obj->lru = item;
        }
        return ;
    }

    if (obj->size < obj->capacity) {
        item = &obj->data[obj->size ++];
        item->key = key;
        item->value = value;
        if (obj->size == 1) {
            item->prev = item;
            item->next = item;
        } else {
            item->next = obj->lru;
            item->prev = obj->lru->prev;
            item->next->prev = item;
            item->prev->next = item;
        }

        obj->lru = item;
    } else {
        item = obj->lru->prev;
        int ok = hash_key(item->key, obj->capacity);
        if (item == obj->hash[ok]) {
            obj->hash[ok] = item->hn;
            if (obj->hash[ok])
                obj->hash[ok]->hp = NULL;
        } else {
            item->hp->hn = item->hn;
            if (item->hn)
                item->hn->hp = item->hp;
        }
        obj->lru = item;
        item->key = key;
        item->value = value;
    }
    item->hp = NULL;
    item->hn = obj->hash[k];
    if (obj->hash[k])
        obj->hash[k]->hp = item;
    obj->hash[k] = item;
}

void lRUCacheFree(LRUCache* obj) {
    if (obj == NULL)
        return ;
    free(obj->data);
    free(obj->hash);
    free(obj);
}
/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
// @lc code=end

