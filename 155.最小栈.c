/*
 * @lc app=leetcode.cn id=155 lang=c
 *
 * [155] 最小栈
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (55.09%)
 * Likes:    642
 * Dislikes: 0
 * Total Accepted:    151.9K
 * Total Submissions: 275.7K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 
 * push(x) —— 将元素 x 推入栈中。
 * pop() —— 删除栈顶的元素。
 * top() —— 获取栈顶元素。
 * getMin() —— 检索栈中的最小元素。
 * 
 * 
 * 
 * 
 * 示例:
 * 
 * 输入：
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 * 
 * 输出：
 * [null,null,null,null,-3,null,0,-2]
 * 
 * 解释：
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * pop、top 和 getMin 操作总是在 非空栈 上调用。
 * 
 * 
 */

// @lc code=start



#define MAXSIZE 1600
typedef struct {
    int *data;
    int top;
} MinStack;
MinStack* minStackCreate() {
    MinStack *obj=(MinStack *)malloc(sizeof(MinStack));
    obj->data=(int *)malloc(MAXSIZE*sizeof(int));
    obj->top=-1;
    return obj;
}
void minStackPush(MinStack* obj, int x) {
  if(obj->top==MAXSIZE-1){
      
  }else if(obj->top==-1){
      obj->top++;
      obj->data[obj->top]=x;
      obj->top++;
      obj->data[obj->top]=x;
  }else{
      int tmp=obj->data[obj->top];
      obj->top++;
      obj->data[obj->top]=x;
      if(tmp<x){
        obj->top++;
        obj->data[obj->top]=tmp;
      }else{
        obj->top++;
        obj->data[obj->top]=x;
      }
  }
}
void minStackPop(MinStack* obj) {
  if(obj->top==-1){
      
  }else{
      obj->top--;
      obj->top--;
  }
}
int minStackTop(MinStack* obj) {
  if(obj->top==-1)
      return;
  return obj->data[obj->top-1];
}
int minStackGetMin(MinStack* obj) {
  return obj->data[obj->top];
}
void minStackFree(MinStack* obj) {
    free(obj->data);
    obj->data=NULL;
    free(obj);
    obj=NULL;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
// @lc code=end

