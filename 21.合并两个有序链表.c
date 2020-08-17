/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (63.93%)
 * Likes:    1216
 * Dislikes: 0
 * Total Accepted:    343.7K
 * Total Submissions: 537.6K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
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


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p = head;
    while (l1 && l2){
        if (l1 -> val < l2 -> val){
            head -> next = l1;
            head = l1;
            l1 = l1 -> next; 
        }
        else{
            head -> next = l2;
            head = l2;
            l2 = l2 -> next;
        }
    }
    head -> next = l1 ? l1 : l2;
    return p -> next;
}
// @lc code=end

