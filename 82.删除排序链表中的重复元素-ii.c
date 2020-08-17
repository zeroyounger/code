/*
 * @lc app=leetcode.cn id=82 lang=c
 *
 * [82] 删除排序链表中的重复元素 II
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (48.87%)
 * Likes:    346
 * Dislikes: 0
 * Total Accepted:    60.7K
 * Total Submissions: 124.2K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->3->4->4->5
 * 输出: 1->2->5
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->1->2->3
 * 输出: 2->3
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


struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL || head->next == NULL) return head;
    struct ListNode HEAD = {NULL, 0};
    struct ListNode* p1 = head;
    struct ListNode* p2 = &HEAD;
    int n,value;
    while (p1) {
        struct ListNode* tmp = p1;
        for (n = 0,value = p1->val; p1 != NULL && p1->val == value; ++n) //计算值为 value 的节点数量
            p1 = p1->next;
        if (n == 1) {  //节点数量等于1，就加入返回链表
            p2->next = tmp;
            p2 = tmp;
        }
    }
    p2->next = NULL;
    return HEAD.next;
}


// @lc code=end

