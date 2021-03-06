/*
 * @lc app=leetcode.cn id=86 lang=c
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (59.28%)
 * Likes:    243
 * Dislikes: 0
 * Total Accepted:    48.5K
 * Total Submissions: 81.8K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 * 
 * 你应当保留两个分区中每个节点的初始相对位置。
 * 
 * 示例:
 * 
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5
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


struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode * pre = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * aft = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * preCur = pre;
    struct ListNode * aftCur = aft;
    while (head != NULL) {
        if (head->val < x) {
            preCur->next = head;
            preCur = preCur->next;
        } else {
            aftCur->next = head;
            aftCur = aftCur->next;
        }
        head = head->next;
    }
    aftCur->next = NULL;
    preCur->next = aft->next;
    return pre->next;
}


// @lc code=end

