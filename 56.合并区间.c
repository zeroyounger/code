/*
 * @lc app=leetcode.cn id=56 lang=c
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (42.88%)
 * Likes:    559
 * Dislikes: 0
 * Total Accepted:    131.2K
 * Total Submissions: 306K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: intervals = [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 * 注意：输入类型已于2019年4月15日更改。 请重置默认代码定义以获取新方法签名。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * intervals[i][0] <= intervals[i][1]
 * 
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void *p1, const void *p2){   
    return ((int **)p1)[0][0] - ((int **)p2)[0][0];
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int **listIn = intervals;
    int len = intervalsSize;
    int **listOut;  
    int count;    
    int i;
    qsort(listIn, len, sizeof(listIn[0]), compare);
    for (i=0,count=0,listOut=NULL; i<len; i++){
        int tailOutRow = count == 0 ? -1 : count-1;
        int tailOutEnd = count == 0 ? 0 : listOut[tailOutRow][1];
        int curInStart = listIn[i][0];
        int curInEnd = listIn[i][1];
        if (i==0 || curInStart>tailOutEnd) {
            count++;
            tailOutRow++;
            listOut = (int **)realloc(listOut, sizeof(int *)*count);
            listOut[tailOutRow] = (int *)malloc(sizeof(int)*2);
            listOut[tailOutRow][0] = curInStart;
            listOut[tailOutRow][1] = curInEnd;            
        }
        else
            listOut[tailOutRow][1] = curInEnd > tailOutEnd ? curInEnd : tailOutEnd;                     
    }
    *returnColumnSizes = (int *)malloc(sizeof(int)*count);        
    for (i=0; i<count; i++)
        (*returnColumnSizes)[i] = 2;
    *returnSize = count;    
    return listOut;
}
// @lc code=end

