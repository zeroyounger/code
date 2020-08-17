/*
 * @lc app=leetcode.cn id=43 lang=c
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (44.53%)
 * Likes:    460
 * Dislikes: 0
 * Total Accepted:    100.2K
 * Total Submissions: 224.9K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 示例 1:
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 说明：
 * 
 * 
 * num1 和 num2 的长度小于110。
 * num1 和 num2 只包含数字 0-9。
 * num1 和 num2 均不以零开头，除非是数字 0 本身。
 * 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 * 
 * 
 */

// @lc code=start


char * multiply(char * num1, char * num2){
    int length1 = strlen(num1);
    int length2 = strlen(num2);
    int totalLength = length1 + length2;                     //获取相乘后字符串的总有效位数
    int charIndex = 0;                                       //定义负责索引字段
    int valueIndex = 0;
    int *value = (int *)malloc(sizeof(int) * totalLength);
    memset(value, 0, sizeof(int) * totalLength);
    char *result = (char *)malloc(sizeof(char) * (totalLength + 1));
    for(int i = length1  - 1; i >= 0; i--)
        for(int j = length2 - 1; j >= 0; j--)
            value[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
    for(int i= totalLength - 1; i > 0; i--){                 //获取每个位置上面的数字并处理进位
        value[i - 1] += value[i] / 10;
        value[i] %= 10;
    }
    while(value[valueIndex] == 0 && valueIndex < totalLength -1 )
        valueIndex++;                                        //忽略掉前面多余的0，但是最高位也就是唯一的一位0不能忽略
    while(valueIndex < totalLength)
        result[charIndex++] = value[valueIndex++] + '0';
    result[charIndex] = '\0';                                //默认补上字符串的终止符
    return result;   
}


// @lc code=end

