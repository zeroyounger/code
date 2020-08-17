/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (39.24%)
 * Likes:    943
 * Dislikes: 0
 * Total Accepted:    216.1K
 * Total Submissions: 550.6K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 
 * 示例：
 * 
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 
 * 
 * 说明：
 * 
 * 给定的 n 保证是有效的。
 * 
 * 进阶：
 * 
 * 你能尝试使用一趟扫描实现吗？
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


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode ** cur = &head; // 第一个指针
    struct ListNode ** fol = &head; // 间隔为 n 的跟随指针
    // cur 先走 n 步
    for (; n > 0; n--)
        cur = &((*cur)->next);
    // 两指针同时移动
    while (*cur) {
        cur = &((*cur)->next);
        fol = &((*fol)->next);
    }
    // 记录待移除节点
    struct ListNode * tmp = *fol;
    // 跨过待移除节点
    *fol = (*fol)->next;
    free(tmp);
    return head;
}


// @lc code=end

