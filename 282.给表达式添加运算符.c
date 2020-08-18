/*
 * @lc app=leetcode.cn id=282 lang=c
 *
 * [282] 给表达式添加运算符
 *
 * https://leetcode-cn.com/problems/expression-add-operators/description/
 *
 * algorithms
 * Hard (33.99%)
 * Likes:    132
 * Dislikes: 0
 * Total Accepted:    3.6K
 * Total Submissions: 10.6K
 * Testcase Example:  '"123"\n6'
 *
 * 给定一个仅包含数字 0-9 的字符串和一个目标值，在数字之间添加二元运算符（不是一元）+、- 或 * ，返回所有能够得到目标值的表达式。
 * 
 * 示例 1:
 * 
 * 输入: num = "123", target = 6
 * 输出: ["1+2+3", "1*2*3"] 
 * 
 * 
 * 示例 2:
 * 
 * 输入: num = "232", target = 8
 * 输出: ["2*3+2", "2+3*2"]
 * 
 * 示例 3:
 * 
 * 输入: num = "105", target = 5
 * 输出: ["1*0+5","10-5"]
 * 
 * 示例 4:
 * 
 * 输入: num = "00", target = 0
 * 输出: ["0+0", "0-0", "0*0"]
 * 
 * 
 * 示例 5:
 * 
 * 输入: num = "3456237490", target = 9191
 * 输出: []
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void helper(char* num, int len, int start, int target, long long sum, long long pre, char* stack, int top, char*** arr, int* returnSize){
    if(start == len){
        if(target == sum){
            stack[++top] = '\0';
            *returnSize += 1; 
            *arr = (char**)realloc(*arr, sizeof(char*)*(*returnSize));
            (*arr)[*returnSize-1] = (char*)malloc(sizeof(char)*(top+1));
            for(int i = 0; i <= top; i++)
                (*arr)[*returnSize-1][i] = stack[i];
        }
        return ; 
    }
    long long val = 0;
    int index = top+1;
    for(int i = start; i < len; i++){
        val = 10*val + num[i] - '0';
        if(start == 0){
            stack[top+1] = num[i];
            helper(num, len, i+1, target, val, val, stack, top+1, arr, returnSize);
        }
        else{
            stack[top+2] = num[i];
            stack[index] = '-';
            helper(num, len, i+1, target, sum-val, -1*val, stack, top+2, arr, returnSize);
            stack[index] = '+';
            helper(num, len, i+1, target, sum+val, val, stack, top+2, arr, returnSize);
            stack[index] = '*';
            helper(num, len, i+1, target, sum-pre+pre*val, pre*val, stack, top+2, arr, returnSize);
        }
        if(num[start] == '0') break;
        top++;
    }
}
char** addOperators(char* num, int target, int* returnSize){
    char** arr = (char**)malloc(sizeof(char*));
    *returnSize = 0;
    int len = strlen(num);
    if(len == 0) return arr;
    char* stack = (char*)malloc(sizeof(char)*2*len);
    int top = -1;
    helper(num, len, 0, target, 0, 0, stack, top, &arr, returnSize);
    return arr;
}
// @lc code=end

