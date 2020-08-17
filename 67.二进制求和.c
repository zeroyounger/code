/*
 * @lc app=leetcode.cn id=67 lang=c
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (54.39%)
 * Likes:    458
 * Dislikes: 0
 * Total Accepted:    120.3K
 * Total Submissions: 221.2K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串，返回它们的和（用二进制表示）。
 * 
 * 输入为 非空 字符串且只包含数字 1 和 0。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个字符串仅由字符 '0' 或 '1' 组成。
 * 1 <= a.length, b.length <= 10^4
 * 字符串如果不是 "0" ，就都不含前导零。
 * 
 * 
 */

// @lc code=start


void Reverse(char *s,int n){ 
    for(int i=0,j=n-1;i<j;i++,j--){ 
        char c=s[i]; 
        s[i]=s[j]; 
        s[j]=c; 
    } 
}

char * addBinary(char * a, char * b){
    int c=0,i=strlen(a)-1,j=strlen(b)-1,k=0;
    char *s=(char*)calloc(i+j+3,sizeof(char));
    while(i >= 0 || j >= 0 || c == 1){
        c += i >= 0 ? a[i--] - '0' : 0;
        c += j >= 0 ? b[j--] - '0' : 0;
        s[k]=(c & 1) + '0';
        k++;
        c >>= 1;
    }
    Reverse(s,strlen(s));
    return s;
}

// @lc code=end

