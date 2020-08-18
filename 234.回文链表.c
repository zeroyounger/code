/*
 * @lc app=leetcode.cn id=234 lang=c
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (43.04%)
 * Likes:    605
 * Dislikes: 0
 * Total Accepted:    117K
 * Total Submissions: 271.8K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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

bool isPalindrome(struct ListNode* head){
    if(head == NULL || head->next == NULL){
        return true;
    }
    struct ListNode* mid1 = head;
    struct ListNode* tmp = head->next;
    while(tmp && tmp->next != NULL){
        mid1 = mid1->next;
        tmp = tmp->next->next;
    }
    struct ListNode* mid2 = mid1->next;
    struct ListNode* cur = mid2->next;
    while(cur != NULL){
        mid2->next = cur->next;
        cur->next = mid1->next;
        mid1->next = cur;
        cur = mid2->next;
    }
    mid2 = mid1->next;
    cur = head;
    while(mid2 != NULL){
        if(cur->val != mid2->val){
            return false;
        }
        cur = cur->next;
        mid2 = mid2->next;
    }
    return true;
}

// @lc code=end

