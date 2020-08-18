/*
 * @lc app=leetcode.cn id=166 lang=c
 *
 * [166] 分数到小数
 *
 * https://leetcode-cn.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (27.21%)
 * Likes:    153
 * Dislikes: 0
 * Total Accepted:    14.3K
 * Total Submissions: 52.7K
 * Testcase Example:  '1\n2'
 *
 * 给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。
 * 
 * 如果小数部分为循环小数，则将循环的部分括在括号内。
 * 
 * 示例 1:
 * 
 * 输入: numerator = 1, denominator = 2
 * 输出: "0.5"
 * 
 * 
 * 示例 2:
 * 
 * 输入: numerator = 2, denominator = 1
 * 输出: "2"
 * 
 * 示例 3:
 * 
 * 输入: numerator = 2, denominator = 3
 * 输出: "0.(6)"
 * 
 * 
 */

// @lc code=start


struct HashMapNode {
    int key;
    int val;
    UT_hash_handle hh;
};
struct HashMapNode* hashMap = NULL;
int hashMapAdd(int key, int val) {
    struct HashMapNode* node;
    HASH_FIND_INT(hashMap, &key, node);
    if(node != NULL){
        return node->val;
    }
    node = (struct HashMapNode*)malloc(sizeof(struct HashMapNode));
    node->key = key;
    node->val = val;
    HASH_ADD_INT(hashMap, key, node);
    return -1;
}
char * fractionToDecimal(int numerator, int denominator){
    char* buf = (char*)malloc(sizeof(char) * 1024);
    int pos;
    long num = numerator, den = denominator;
    num = labs(num); den = labs(den);
    if(numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0){
        sprintf(buf, "-%ld", num / den);
    }else{
        sprintf(buf, "%ld", num / den);
    }
    pos = strlen(buf);
    num = num % den;
    if(num){
        buf[pos++] = '.';
        int start = -1;
        while(num && (start = hashMapAdd(num, pos)) == -1){
            buf[pos++] = (num * 10 / den) + '0';
            num = num * 10 % den;
        }
    
        if(start != -1){
            for(int i = pos++; i > start; i--){
                buf[i] = buf[i-1];
            }
            buf[start] = '(';
            buf[pos++] = ')';
        }
    }
    buf[pos] = '\0';  
    hashMap = NULL;
    return buf;
}
// @lc code=end

