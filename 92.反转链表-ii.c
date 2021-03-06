/*
 * @lc app=leetcode.cn id=92 lang=c
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (51.11%)
 * Likes:    473
 * Dislikes: 0
 * Total Accepted:    68.5K
 * Total Submissions: 134K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
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


struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
	struct ListNode *p, *q, *new;
	struct ListNode HEAD;
	int index, num = m;
	HEAD.next = head;
	if(m >= n) {
		return head;
	}
	new = &HEAD;
	while( num > 1 ) {
		new = new->next;
		num--;
	}
	p = new->next;
	index = 0;
	while(index < n-m){
		q = p->next;
		p->next = q->next;
		q->next = new->next;
		new->next = q;
		index++;
	}
	return HEAD.next;
}

// @lc code=end

