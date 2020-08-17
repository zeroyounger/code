/*
 * @lc app=leetcode.cn id=61 lang=c
 *
 * [61] 旋转链表
 *
 * https://leetcode-cn.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (40.53%)
 * Likes:    319
 * Dislikes: 0
 * Total Accepted:    78.8K
 * Total Submissions: 194.5K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->4->5->NULL, k = 2
 * 输出: 4->5->1->2->3->NULL
 * 解释:
 * 向右旋转 1 步: 5->1->2->3->4->NULL
 * 向右旋转 2 步: 4->5->1->2->3->NULL
 * 
 * 
 * 示例 2:
 * 
 * 输入: 0->1->2->NULL, k = 4
 * 输出: 2->0->1->NULL
 * 解释:
 * 向右旋转 1 步: 2->0->1->NULL
 * 向右旋转 2 步: 1->2->0->NULL
 * 向右旋转 3 步: 0->1->2->NULL
 * 向右旋转 4 步: 2->0->1->NULL
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


struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode* cur = head;
    int n = 1;
    if( NULL == head || NULL == head->next || 0 == k)
        return head;
    while( NULL != cur->next ){
        cur = cur->next;
        n++;
    }
    k %= n;
    k = n - k - 1;
    cur->next = head;
    cur = head;
    while( k-- > 0 ) cur = cur->next;
    head = cur->next;
    cur->next = NULL;
    return head;
}


// @lc code=end

