/*
 * @lc app=leetcode.cn id=232 lang=c
 *
 * [232] 用栈实现队列
 *
 * https://leetcode-cn.com/problems/implement-queue-using-stacks/description/
 *
 * algorithms
 * Easy (64.83%)
 * Likes:    213
 * Dislikes: 0
 * Total Accepted:    58.4K
 * Total Submissions: 90K
 * Testcase Example:  '["MyQueue","push","push","peek","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * 使用栈实现队列的下列操作：
 * 
 * 
 * push(x) -- 将一个元素放入队列的尾部。
 * pop() -- 从队列首部移除元素。
 * peek() -- 返回队列首部的元素。
 * empty() -- 返回队列是否为空。
 * 
 * 
 * 
 * 
 * 示例:
 * 
 * MyQueue queue = new MyQueue();
 * 
 * queue.push(1);
 * queue.push(2);  
 * queue.peek();  // 返回 1
 * queue.pop();   // 返回 1
 * queue.empty(); // 返回 false
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty
 * 操作是合法的。
 * 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
 * 假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。
 * 
 * 
 */

// @lc code=start

typedef struct MyQueue_tag {
  int value; 
  int count;         /*栈内元素个数*/
  struct MyQueue_tag *next; /*指向栈的下一个元素*/    
} MyQueue;
MyQueue* myQueueCreate() {
  MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue));
  if(NULL == queue)
  {
    return NULL;
  }
  queue->next = NULL;
  queue->count = 0;
  return queue;
}
void myQueuePush(MyQueue* obj, int x) {
  MyQueue *srcQueue = NULL;
  MyQueue *newnode = (MyQueue *)malloc(sizeof(MyQueue));
  if(NULL == newnode)
  {
    return;
  }
  srcQueue = obj;
  while(srcQueue->next != NULL)
  {
    srcQueue = srcQueue->next;
  }
  newnode->value = x;
  newnode->next = NULL;
  srcQueue->next = newnode;
  obj->count++;
}
int myQueuePop(MyQueue* obj) {
  int value = 0;
  if(obj->count == 0)
  {
    return value;
  }
  value = obj->next->value;
  MyQueue *temp = obj->next;
  obj->next = obj->next->next;
  obj->count--;
  if(temp != NULL)
    free(temp);
  temp = NULL;
  return value;
}
int myQueuePeek(MyQueue* obj) {
  int value = 0;
  if(obj->count == 0)
  {
    return value;
  }
  value = obj->next->value;
  return value;
}
bool myQueueEmpty(MyQueue* obj) {
  return (obj->count == 0) ? true : false;
}
void myQueueFree(MyQueue* obj) {
  if(obj != NULL)
  {
    free(obj);
    obj = NULL;
  }
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
// @lc code=end

