/*
 * @lc app=leetcode.cn id=6 lang=c
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (48.54%)
 * Likes:    793
 * Dislikes: 0
 * Total Accepted:    160.3K
 * Total Submissions: 330.2K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * 
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * string convert(string s, int numRows);
 * 
 * 示例 1:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 * 
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 * 
 */

// @lc code=start


char * convert(char * s, int numRows){
    if (numRows == 1)
        return s;
    int len = strlen(s);
    char *res = (char*)malloc((len + 1) * sizeof(char));
    int *a = (int*)malloc(numRows * sizeof(int)), *b = (int*)malloc(numRows * sizeof(int));
    int i, j, k = 0;

    a[0] = b[0] = a[numRows - 1] = b[numRows - 1] = 2 * (numRows - 1);//第0行和第(numRows - 1)行值固定不变
    //a, b数组存储交替变换的间隔值
    for (i = 1; i < numRows / 2 + numRows % 2; i++){
        a[i] = 2 * (numRows - 1 - i);
        b[i] = 2 * i;
        a[numRows - 1 - i] = b[i];
        b[numRows - 1 - i] = a[i];
    }
    for (i = 0; i < numRows; i++){
    	int cnt = 0;
        for (j = i; j < len; ){
            res[k++] = s[j];
            cnt++;
            if (cnt & 1)
                j += a[i];
            else
                j += b[i];  
        }
    }
    res[k] = '\0';
    return res;
}


// @lc code=end

