/*
 * @lc app=leetcode.cn id=68 lang=c
 *
 * [68] 文本左右对齐
 *
 * https://leetcode-cn.com/problems/text-justification/description/
 *
 * algorithms
 * Hard (44.19%)
 * Likes:    94
 * Dislikes: 0
 * Total Accepted:    10.6K
 * Total Submissions: 24K
 * Testcase Example:  '["This", "is", "an", "example", "of", "text", "justification."]\n16'
 *
 * 给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
 * 
 * 你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。
 * 
 * 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
 * 
 * 文本的最后一行应为左对齐，且单词之间不插入额外的空格。
 * 
 * 说明:
 * 
 * 
 * 单词是指由非空格字符组成的字符序列。
 * 每个单词的长度大于 0，小于等于 maxWidth。
 * 输入单词数组 words 至少包含一个单词。
 * 
 * 
 * 示例:
 * 
 * 输入:
 * words = ["This", "is", "an", "example", "of", "text", "justification."]
 * maxWidth = 16
 * 输出:
 * [
 * "This    is    an",
 * "example  of text",
 * "justification.  "
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * words = ["What","must","be","acknowledgment","shall","be"]
 * maxWidth = 16
 * 输出:
 * [
 * "What   must   be",
 * "acknowledgment  ",
 * "shall be        "
 * ]
 * 解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
 * 因为最后一行应为左对齐，而不是左右两端对齐。       
 * ⁠    第二行同样为左对齐，这是因为这行只包含一个单词。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * words =
 * ["Science","is","what","we","understand","well","enough","to","explain",
 * "to","a","computer.","Art","is","everything","else","we","do"]
 * maxWidth = 20
 * 输出:
 * [
 * "Science  is  what we",
 * ⁠ "understand      well",
 * "enough to explain to",
 * "a  computer.  Art is",
 * "everything  else  we",
 * "do                  "
 * ]
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fullJustify(char ** words, int wordsSize, int maxWidth, int* returnSize){
    *returnSize = 0; 
    char ** res = (char**)malloc(wordsSize * sizeof(char*));
    int*  len = (int*)malloc(wordsSize * sizeof(int));
    int*  blank = (int*)malloc(wordsSize * sizeof(int));
    memset(len, 0, wordsSize * sizeof(int));
    memset(blank, 0, wordsSize * sizeof(int));
    int count = 0;
    for(int i = 0; i < wordsSize; ){
        if (len[count] + blank[count] + strlen(words[i]) > maxWidth){
            count++;
        }
        else{
            len[count] += strlen(words[i]);
            blank[count]++;
            i++;
        }

    }
    int widx1= 0;
    count++;
    for(int i = 0; i < count; i++)
        widx1 += blank[i];
    int widx= 0;
    for(int i = 0; i < count; i++){
        res[i] = (char*)malloc(maxWidth + 1);
        memset(res[i], ' ', maxWidth);
        res[i][maxWidth] = '\0';
        if (i == count -1){
            char* p = res[i];
            for(int j = 0; j <blank[i]; j++){
                memcpy(p, words[widx + j], strlen(words[widx + j]));
                p += strlen(words[widx + j]) + 1;
            }
        }
        else{
            char* p = res[i];
            int fillblank = maxWidth - len[i];
            if (blank[i] ==1){
                memcpy(p, words[widx], strlen(words[widx]));
            }
            else{
                int y = fillblank/(blank[i]-1);
                int m = fillblank%(blank[i]-1);
                memcpy(p, words[widx], strlen(words[widx]));
                for(int j = 1; j <blank[i]; j++){
                    if (m > 0){
                        p += strlen(words[widx + j -1]) + y + 1;
                        m --;
                    }
                    else{
                        p += strlen(words[widx + j -1]) + y;
                    }
                    memcpy(p, words[widx + j], strlen(words[widx + j]));
                }
            }
            widx += blank[i];
        }
    }
    *returnSize = count;
    return res;
}


// @lc code=end

