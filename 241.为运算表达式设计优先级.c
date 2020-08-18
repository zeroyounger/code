/*
 * @lc app=leetcode.cn id=241 lang=c
 *
 * [241] 为运算表达式设计优先级
 *
 * https://leetcode-cn.com/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (71.98%)
 * Likes:    234
 * Dislikes: 0
 * Total Accepted:    13.9K
 * Total Submissions: 19.3K
 * Testcase Example:  '"2-1-1"'
 *
 * 给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及
 * * 。
 * 
 * 示例 1:
 * 
 * 输入: "2-1-1"
 * 输出: [0, 2]
 * 解释: 
 * ((2-1)-1) = 0 
 * (2-(1-1)) = 2
 * 
 * 示例 2:
 * 
 * 输入: "2*3-4*5"
 * 输出: [-34, -14, -10, -10, 10]
 * 解释: 
 * (2*(3-(4*5))) = -34 
 * ((2*3)-(4*5)) = -14 
 * ((2*(3-4))*5) = -10 
 * (2*((3-4)*5)) = -10 
 * (((2*3)-4)*5) = 10
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define compute(leftNums, leftSize, l, rightNums, rightSize, r, returnNums, returnSize, symbol) \
{ \
    leftSize = 0; \
    rightSize = 0; \
    leftNums = NULL; \
    rightNums = NULL; \
    leftNums = _diffWaysToCompute(input, start, i - 1, &leftSize); \
    rightNums = _diffWaysToCompute(input, i + 1, end, &rightSize); \
    for(l = 0; l < leftSize; l++){ \
	for(r = 0; r < rightSize; r++){ \
            returnNums[(*returnSize)++] = leftNums[l] symbol rightNums[r]; \
	} \
    } \
    free(leftNums); \
    free(rightNums); \
}

int* _diffWaysToCompute(char* input, int start, int end, int* returnSize){
    int i, leftSize, rightSize, l, r;
    int *leftNums, *rightNums;
    int *returnNums = (int*)malloc(sizeof(int) * 4096);
    bool isNumber = true;
    for(i = start; i <= end; i++){
        if(!(input[i] >= '0' && input[i] <= '9')){		
            isNumber = false;		
	    switch(input[i]){
	        case'+':
		    compute(leftNums, leftSize, l, rightNums, rightSize, r, returnNums, returnSize, +);
	            break;
		case '-': 
		    compute(leftNums, leftSize, l, rightNums, rightSize, r, returnNums, returnSize, -);
		    break;
         	case '*': 
		    compute(leftNums, leftSize, l, rightNums, rightSize, r, returnNums, returnSize, *);
		    break;
		case '/': 
		    compute(leftNums, leftSize, l, rightNums, rightSize, r, returnNums, returnSize, /);
		    break;
		default: 
		    break;
	    }
	}
    }
    if(isNumber){
        char* buf = (char*)malloc(sizeof(char) * (end - start + 2));
	for(i = 0; start + i <= end; i++){
	    buf[i] = input[start + i]; 
	}
	buf[i] = '\0';
	returnNums[(*returnSize)++] = atoi(buf);
	free(buf);
    }
    return returnNums;
}
int* diffWaysToCompute(char * input, int* returnSize){
    *returnSize = 0;
    int *returnNums = (int*)malloc(sizeof(int) * 1024);
    returnNums = _diffWaysToCompute(input, 0, strlen(input) - 1, returnSize);
    return returnNums;	
}


// @lc code=end

