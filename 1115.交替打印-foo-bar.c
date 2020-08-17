/*
 * @lc app=leetcode.cn id=1115 lang=c
 *
 * [1115] 交替打印FooBar
 *
 * https://leetcode-cn.com/problems/print-foobar-alternately/description/
 *
 * concurrency
 * Medium (55.20%)
 * Likes:    71
 * Dislikes: 0
 * Total Accepted:    21K
 * Total Submissions: 38K
 * Testcase Example:  '1'
 *
 * 我们提供一个类：
 * 
 * 
 * class FooBar {
 * ⁠ public void foo() {
 * for (int i = 0; i < n; i++) {
 * print("foo");
 * }
 * ⁠ }
 * 
 * ⁠ public void bar() {
 * for (int i = 0; i < n; i++) {
 * print("bar");
 * }
 * ⁠ }
 * }
 * 
 * 
 * 两个不同的线程将会共用一个 FooBar 实例。其中一个线程将会调用 foo() 方法，另一个线程将会调用 bar() 方法。
 * 
 * 请设计修改程序，以确保 "foobar" 被输出 n 次。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: n = 1
 * 输出: "foobar"
 * 解释: 这里有两个线程被异步启动。其中一个调用 foo() 方法, 另一个调用 bar() 方法，"foobar" 将被输出一次。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: n = 2
 * 输出: "foobarfoobar"
 * 解释: "foobar" 将被输出两次。
 * 
 * 
 */

// @lc code=start
typedef struct {
    int n;
} FooBar;

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;
    return obj;
}

void foo(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
    }
}

void bar(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        
        // printBar() outputs "bar". Do not change or remove this line.
        printBar();
    }
}

void fooBarFree(FooBar* obj) {
    
}
// @lc code=end

