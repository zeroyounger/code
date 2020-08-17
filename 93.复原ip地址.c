/*
 * @lc app=leetcode.cn id=93 lang=c
 *
 * [93] 复原IP地址
 *
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (49.15%)
 * Likes:    393
 * Dislikes: 0
 * Total Accepted:    74.9K
 * Total Submissions: 152.5K
 * Testcase Example:  '"25525511135"'
 *
 * 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
 * 
 * 有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
 * 
 * 例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是
 * "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效的 IP 地址。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "25525511135"
 * 输出：["255.255.11.135","255.255.111.35"]
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "0000"
 * 输出：["0.0.0.0"]
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "1111"
 * 输出：["1.1.1.1"]
 * 
 * 
 * 示例 4：
 * 
 * 输入：s = "010010"
 * 输出：["0.10.0.10","0.100.1.0"]
 * 
 * 
 * 示例 5：
 * 
 * 输入：s = "101023"
 * 输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 3000
 * s 仅由数字组成
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void get_ret(char **ret, int *ret_index, int *stack, int len, char *s){
    int index = 0;
    int index_s = 0;
    int i=0;
    int left=0;
    ret[(*ret_index)] = (char *)malloc(sizeof(char) * (len+5));
    for(i=0; i<4; i++){
        left = stack[i];
        while(left){
            ret[(*ret_index)][index++] = s[index_s++];
            left--;
        }
        if(i<3)
            ret[(*ret_index)][index++] = '.';
    }
    ret[(*ret_index)][index++] = '\0';
    (*ret_index)++;
}

void rec(char *s, int len, int index, int left_num, int left_len,
         char **ret, int *ret_index, int *stack, int *stack_index){
    int i, j;
    /* 非法 */
    if(left_num < 0 || left_num*3 < left_len || index > len || left_num<0 || left_len<0 ||
       (left_num==0 && left_len!=0)) return;
    /* 设置符合的结果到返回字符串 */
    if(left_num == 0 && left_len == 0){
        get_ret(ret, ret_index, stack, len, s);
        return ;
    }
    /* 每次尝试1，2，3个字符 */
    for(i=1; i<=3; i++){
        /* 排除超过255的数字 */
        if(i==3 && (index+i > len || memcmp(&s[index], "255", 3) > 0))
            continue;
        /* 排除以0开头的数字 */
        if(i!=1 && s[index]=='0')
            continue;
        stack[(*stack_index)++] = i;
        rec(s, len, index+i, left_num-1, left_len-i, ret, ret_index, stack, stack_index);
        (*stack_index)--;
    }
}
#define LEN 0xffff
int get_str_len(char *s){
    int i=0;
    while(*s++ != '\0')
        i++;
    return i;
}
char ** restoreIpAddresses(char * s, int* returnSize){
   char **ret = (char **)malloc(sizeof(char) * LEN);
   int ret_index = 0;
   int stack[4];
   int stack_index = 0;
   int len = get_str_len(s);
   rec(s, len, 0, 4, len, ret, &ret_index, stack, &stack_index);
   *returnSize = ret_index;
   return ret;
}
// @lc code=end

