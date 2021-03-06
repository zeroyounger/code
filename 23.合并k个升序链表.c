/*
 * @lc app=leetcode.cn id=23 lang=c
 *
 * [23] 合并K个升序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (52.74%)
 * Likes:    856
 * Dislikes: 0
 * Total Accepted:    157.4K
 * Total Submissions: 298.4K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 * 
 * 
 * 示例 2：
 * 
 * 输入：lists = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 输入：lists = [[]]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeKListsSub(struct ListNode** lists, int listsSize){
    struct ListNode* temp = NULL;
    int val = INT_MAX;
    int pos = -1;
    int i;
    for(i = 0; i < listsSize;i++){
        if(lists[i]){
            if(val > lists[i]->val){
                val = lists[i]->val;
                pos = i;
            }
        }
    }
    if(pos != -1){
        temp = lists[pos];
        lists[pos] = lists[pos]->next;
        temp->next = mergeKListsSub(lists,listsSize);
    }
    return temp;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    return mergeKListsSub(lists,listsSize);
}
// @lc code=end

