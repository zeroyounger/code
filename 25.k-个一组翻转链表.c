/*
 * @lc app=leetcode.cn id=25 lang=c
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (62.57%)
 * Likes:    688
 * Dislikes: 0
 * Total Accepted:    93.5K
 * Total Submissions: 149.5K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 
 * 
 * 示例：
 * 
 * 给你这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
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


struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (!head) return head;
    int len=0;
    struct ListNode *p=head, *q= NULL;
    while(p&&(len<k))
        p=p->next,len++;
    if (len<k)
        return head;
    struct ListNode h;
    h.val = 0;
    h.next = NULL;
    p=head;
    while(len--){
        q=p;
        p=p->next;
        q->next=h.next;
        h.next=q;
    }
    head->next=reverseKGroup(p,k);
    return h.next;
}


// @lc code=end

