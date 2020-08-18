/*
 * @lc app=leetcode.cn id=148 lang=c
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (66.70%)
 * Likes:    685
 * Dislikes: 0
 * Total Accepted:    83.3K
 * Total Submissions: 124.9K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 * 
 * 示例 1:
 * 
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 * 
 * 
 * 示例 2:
 * 
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
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


#define MAX_LEN 102400
int Cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
struct ListNode* sortList(struct ListNode* head){
    int len = 0;
    struct ListNode *cur = head;
    int a[MAX_LEN];
    while (cur != NULL) {
        a[len++] = cur->val;
        cur = cur->next;
    }
    qsort(a, len, sizeof(int), Cmp);
    cur = head;
    int i = 0;
    while (cur != NULL) {
        cur->val = a[i++];
        cur = cur->next;
    }
    return head;
}

// @lc code=end

