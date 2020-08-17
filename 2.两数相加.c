/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (38.04%)
 * Likes:    4762
 * Dislikes: 0
 * Total Accepted:    517.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
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


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int c = 0;
    struct ListNode *head, *cur, *next;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = NULL;
    cur = head;
    while(l1!=NULL || l2!=NULL || c) {
        next=(struct ListNode *)malloc(sizeof(struct ListNode));
        next->next=NULL;
        cur->next=next;
        cur=next;
        l1!=NULL?(c+=l1->val,l1=l1->next):(c+=0);
        l2!=NULL?(c+=l2->val,l2=l2->next):(c+=0);
        cur->val=c%10;
        c=c/10;
    }
    struct ListNode *del = head;
    head=head->next;
    free(del);
    return head;
}


// @lc code=end

