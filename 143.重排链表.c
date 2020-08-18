/*
 * @lc app=leetcode.cn id=143 lang=c
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (56.36%)
 * Likes:    279
 * Dislikes: 0
 * Total Accepted:    34.5K
 * Total Submissions: 61.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 示例 1:
 * 
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 * 
 * 示例 2:
 * 
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
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


struct ListNode *reverse(struct ListNode *head){
    if(head == NULL || head->next == NULL){
        return head;
    }else{
        struct ListNode *newL = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newL;
    }
}
struct ListNode *merge(struct ListNode *l1, struct ListNode *l2){
    struct ListNode *head = l1;
    while(l2){
        struct ListNode *tmpl1 = l1->next;
        l1->next = l2;
        struct ListNode *tmpl2 = l2->next;
        l2->next = tmpl1;
        l1 = tmpl1;
        l2 = tmpl2;
    }
    return head;
}
void reorderList(struct ListNode* head){
    if(head == NULL || head->next == NULL) return;
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    struct ListNode *rev = reverse(slow->next); // 被翻转的后半部分
    slow->next = NULL;
    head = merge(head, rev);
}
// @lc code=end

