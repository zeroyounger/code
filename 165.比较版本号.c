/*
 * @lc app=leetcode.cn id=165 lang=c
 *
 * [165] 比较版本号
 *
 * https://leetcode-cn.com/problems/compare-version-numbers/description/
 *
 * algorithms
 * Medium (42.61%)
 * Likes:    100
 * Dislikes: 0
 * Total Accepted:    22.9K
 * Total Submissions: 53.7K
 * Testcase Example:  '"0.1"\n"1.1"'
 *
 * 比较两个版本号 version1 和 version2。
 * 如果 version1 > version2 返回 1，如果 version1 < version2 返回 -1， 除此之外返回 0。
 * 
 * 你可以假设版本字符串非空，并且只包含数字和 . 字符。
 * 
 * . 字符不代表小数点，而是用于分隔数字序列。
 * 
 * 例如，2.5 不是“两个半”，也不是“差一半到三”，而是第二版中的第五个小版本。
 * 
 * 你可以假设版本号的每一级的默认修订版号为 0。例如，版本号 3.4 的第一级（大版本）和第二级（小版本）修订号分别为 3 和
 * 4。其第三级和第四级修订号均为 0。
 * 
 * 
 * 示例 1:
 * 
 * 输入: version1 = "0.1", version2 = "1.1"
 * 输出: -1
 * 
 * 示例 2:
 * 
 * 输入: version1 = "1.0.1", version2 = "1"
 * 输出: 1
 * 
 * 示例 3:
 * 
 * 输入: version1 = "7.5.2.4", version2 = "7.5.3"
 * 输出: -1
 * 
 * 示例 4：
 * 
 * 输入：version1 = "1.01", version2 = "1.001"
 * 输出：0
 * 解释：忽略前导零，“01” 和 “001” 表示相同的数字 “1”。
 * 
 * 示例 5：
 * 
 * 输入：version1 = "1.0", version2 = "1.0.0"
 * 输出：0
 * 解释：version1 没有第三级修订号，这意味着它的第三级修订号默认为 “0”。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 版本字符串由以点 （.） 分隔的数字字符串组成。这个数字字符串可能有前导零。
 * 版本字符串不以点开始或结束，并且其中不会有两个连续的点。
 * 
 * 
 */

// @lc code=start


int compareVersion(char * version1, char * version2){
    if (version1 == NULL || version2 == NULL) return -1;
    int *val1 = (int *)calloc(1024, sizeof(int));
    int *val2 = (int *)calloc(1024, sizeof(int));
    int len1 = strlen(version1), top1 = 0;
    int len2 = strlen(version2), top2 = 0;
    int i, n;
    for (i = 0, n = 0; i < len1; ++i) {  //解析版本1
        if (version1[i] == '.') {
            val1[top1++] = n;
            n = 0;
        }else n = n*10 + (version1[i] & 0x0f);
    }
    val1[top1++] = n;
    for (i = 0, n = 0; i < len2; ++i) {  //解析版本1
        if (version2[i] == '.') {
            val2[top2++] = n;
            n = 0;
        }else n = n*10 + (version2[i] & 0x0f);
    }
    val2[top2++] = n;
    for (i = 0; i < top1 && i < top2; ++i) {  //比较版本大小
        if      (val1[i] > val2[i]) return 1;
        else if (val1[i] < val2[i]) return -1;
    }
    if (i < top1) {  //由于可能有的版本还没遍历完
        while (i < top1) if (val1[i++]) return 1;  //只要版本后面的数字出现的不是0，就意味着两个版本不一样
    }else{
        while (i < top2) if (val2[i++]) return -1;
    }
    return 0;
} 


// @lc code=end

