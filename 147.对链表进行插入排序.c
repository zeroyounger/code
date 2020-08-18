/*
 * @lc app=leetcode.cn id=147 lang=c
 *
 * [147] 对链表进行插入排序
 *
 * https://leetcode-cn.com/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (65.03%)
 * Likes:    202
 * Dislikes: 0
 * Total Accepted:    37.7K
 * Total Submissions: 58K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 对链表进行插入排序。
 * 
 * 
 * 插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
 * 每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。
 * 
 * 
 * 
 * 插入排序算法：
 * 
 * 
 * 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
 * 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
 * 重复直到所有输入数据插入完为止。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 * 
 * 
 * 示例 2：
 * 
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
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


struct ListNode* insertionSortList(struct ListNode* head){
    if(head==NULL||head->next==NULL) return head;
    struct ListNode* rear,*p,*temp,*q = head;      //rear指向尾结点，q指向倒数第二个结点
    rear = head->next;
    while(rear){
        //找到不是升序的结点
        while(rear&&rear->val>=q->val){
            q = rear;
            rear = rear->next;
        }
        if(rear==NULL)   break;
        temp = rear;
        rear = rear->next;
        q->next = rear;
        //该节点小于头结点
        if(temp->val<head->val){
            temp->next = head;
            head = temp;
        }
        else{
            p = head;
            while(temp->val>p->next->val)
                p = p->next;
            temp->next = p->next;
            p->next = temp;
        }
    }
    return head;
}

// @lc code=end

