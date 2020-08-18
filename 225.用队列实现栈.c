/*
 * @lc app=leetcode.cn id=225 lang=c
 *
 * [225] 用队列实现栈
 *
 * https://leetcode-cn.com/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (65.44%)
 * Likes:    215
 * Dislikes: 0
 * Total Accepted:    67.7K
 * Total Submissions: 103.4K
 * Testcase Example:  '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * 使用队列实现栈的下列操作：
 * 
 * 
 * push(x) -- 元素 x 入栈
 * pop() -- 移除栈顶元素
 * top() -- 获取栈顶元素
 * empty() -- 返回栈是否为空
 * 
 * 
 * 注意:
 * 
 * 
 * 你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty
 * 这些操作是合法的。
 * 你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
 * 你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
 * 
 * 
 */

// @lc code=start


#define LEN 20
typedef struct queue{
    int *data;
    int head;
    int rear;
    int size;
}Queue;
typedef struct {
    Queue *q1,*q2;
} MyStack;

Queue *initQueue(int k){
    Queue *obj=(Queue *)malloc(sizeof(Queue));
    obj->data=(int *)malloc(k*sizeof(int));
    obj->head=-1;
    obj->rear=-1;
    obj->size=k;
    return obj;
}
void enQueue(Queue *obj,int e){
    //入队的时候，此题不必考虑队列满状态情形
    //队列为空的情形
    if(obj->head==-1){
      obj->head=0;
    }
    //队列一般情形
    obj->rear=(obj->rear+1)%obj->size;
    obj->data[obj->rear]=e;
}
int deQueue(Queue *obj){
    //出队的时候，此题不必考虑队列为空的情形
    int a=obj->data[obj->head];
    //特殊情形，队列中只有一个元素
    if(obj->head==obj->rear){
        obj->rear=-1;
        obj->head=-1;
        return a;
    }
    //队列一般情形
    obj->head=(obj->head+1)%obj->size;
    return a;
}
int isEmpty(Queue *obj){
    return obj->head==-1;
}

/** Initialize your data structure here. */
MyStack* myStackCreate() {
    MyStack *obj=(MyStack *)malloc(sizeof(MyStack));
    obj->q1=initQueue(LEN);
    obj->q2=initQueue(LEN);
    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
  //只要我找到一个队列为非空，我就向里面添加元素，如果两个都是空的，那随便哪一个都可以
  if(isEmpty(obj->q1)){
    enQueue(obj->q2,x);
  }else{
    enQueue(obj->q1,x);
  }
}

/** Removes the element on top of the stack and returns that element. */
//栈弹出的时候，有且只有一个队列为非空
int myStackPop(MyStack* obj) {
    //q2为非空的时候，q2出列直到q2中只有一个元素
    if(isEmpty(obj->q1)){
        while(obj->q2->head != obj->q2->rear){
            //q2出列的元素，入列q1
            enQueue(obj->q1,deQueue(obj->q2));
        }
        return  deQueue(obj->q2);
    }
    //反之q1非空
    while(obj->q1->head != obj->q1->rear){
        enQueue(obj->q2,deQueue(obj->q1));
    }
    return  deQueue(obj->q1);
}

/** Get the top element. */
//取栈顶元素，有且只有一个队列为非空，我直接取非空队列的尾部即可
int myStackTop(MyStack* obj) {
    if(isEmpty(obj->q1)){
        return obj->q2->data[obj->q2->rear];
    }
    return obj->q1->data[obj->q1->rear];
}

/** Returns whether the stack is empty. */
//当且仅当两个队列都是空的情形
bool myStackEmpty(MyStack* obj) {
    if(obj->q1->head==-1 && obj->q2->head==-1){
        return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {
    free(obj->q1->data);
    obj->q1->data=NULL;
    free(obj->q1);
    obj->q1=NULL;
    free(obj->q2->data);
    obj->q2->data=NULL;
    free(obj->q2);
    obj->q2=NULL;
    free(obj);
    obj=NULL;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
// @lc code=end

