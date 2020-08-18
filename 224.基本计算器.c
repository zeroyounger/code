/*
 * @lc app=leetcode.cn id=224 lang=c
 *
 * [224] 基本计算器
 *
 * https://leetcode-cn.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (38.33%)
 * Likes:    243
 * Dislikes: 0
 * Total Accepted:    18K
 * Total Submissions: 46.9K
 * Testcase Example:  '"1 + 1"'
 *
 * 实现一个基本的计算器来计算一个简单的字符串表达式的值。
 * 
 * 字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。
 * 
 * 示例 1:
 * 
 * 输入: "1 + 1"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: " 2-1 + 2 "
 * 输出: 3
 * 
 * 示例 3:
 * 
 * 输入: "(1+(4+5+2)-3)+(6+8)"
 * 输出: 23
 * 
 * 说明：
 * 
 * 
 * 你可以假设所给定的表达式都是有效的。
 * 请不要使用内置的库函数 eval。
 * 
 * 
 */

// @lc code=start


int calculate(char * s){
    unsigned int i = 0, tmp = 0, top1 = 0, top2 = 0, flag = 0;
    unsigned int *stack1 = (int *)malloc(sizeof(int) * strlen(s));
    char *stack2 = (char *)malloc(strlen(s));
    unsigned int a, b, res = 0;
    char smb;
    while (s[i] != '\0'){
        if (s[i] >= '0' && s[i] <= '9'){
            tmp = tmp * 10 + s[i] - '0';
            flag = 1;
        }
        else if (flag){
            if (top2 > 0 && stack2[top2-1] == '+'){
                a = stack1[--top1];
                stack1[top1++] = a + tmp;
                top2--;
            }
            else if (top2 > 0 && stack2[top2-1] == '-'){
                a = stack1[--top1];
                stack1[top1++] = a - tmp;
                top2--;
            }
            else{
                stack1[top1++] = tmp;
            }
            tmp = 0;
            flag = 0;
        }
        switch (s[i]){
            case '(':
                stack2[top2++] = '(';
                break;
            case '+':
                stack2[top2++] = '+';
                break;
            case '-':
                stack2[top2++] = '-';
                break;
            case ')':
                top2--;
                if (top2 > 0 && stack2[top2-1] == '+'){
                    a = stack1[--top1];
                    b = stack1[--top1];
                    stack1[top1++] = a + b;
                    top2--;
                }
                else if (top2 > 0 && stack2[top2-1] == '-'){
                    a = stack1[--top1];
                    b = stack1[--top1];
                    stack1[top1++] = b - a;
                    top2--;
                }
                break;
            default:
                break;
        }
        i++;
    }
    if (flag){
        if (top2 > 0 && stack2[top2-1] == '+'){
            a = stack1[--top1];
            stack1[top1++] = a + tmp;
        }
        else if (top2 > 0 && stack2[top2-1] == '-'){
            a = stack1[--top1];
            stack1[top1++] = a - tmp;
        }
        else{
            stack1[top1++] = tmp;
        }
    }
    res = stack1[0];
    free(stack1);
    free(stack2);
    return res;
}


// @lc code=end

