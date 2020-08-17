/*
 * @lc app=leetcode.cn id=57 lang=c
 *
 * [57] 插入区间
 *
 * https://leetcode-cn.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (37.47%)
 * Likes:    178
 * Dislikes: 0
 * Total Accepted:    27.9K
 * Total Submissions: 74.4K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * 给出一个无重叠的 ，按照区间起始端点排序的区间列表。
 * 
 * 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
 * 输出：[[1,5],[6,9]]
 * 
 * 
 * 示例 2：
 * 
 * 输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * 输出：[[1,2],[3,10],[12,16]]
 * 解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
 * 
 * 
 * 
 * 
 * 注意：输入类型已在 2019 年 4 月 15 日更改。请重置为默认代码定义以获取新的方法签名。
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int pushbackInterval(int **result, int num, int *element, int *colSize) {
    result[num] = (int*)malloc(sizeof(int)*10);
    result[num][0] = element[0];
    result[num][1] = element[1];
    colSize[num] = 2;
    return num + 1;
}
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    int *insert = newInterval;
    int **result = (int**)malloc(sizeof(int*)*(intervalsSize+1));
    *returnColumnSizes = (int*)malloc(sizeof(int)*(intervalsSize+1));
    int num = 0;
    for (int i = 0; i < intervalsSize; i++) {
        int *e = intervals[i];
        if (!insert) {
            num = pushbackInterval(result, num, e, *returnColumnSizes);
            continue;
        }
        if (e[1] < insert[0]) {
            num = pushbackInterval(result, num, e, *returnColumnSizes);
            continue;
        }
        if (e[0] > insert[1]) {
            num = pushbackInterval(result, num, insert, *returnColumnSizes);
            insert = NULL;
            num = pushbackInterval(result, num, e, *returnColumnSizes);
            continue;
        }
        insert[0] = insert[0] < e[0] ? insert[0] : e[0];
        insert[1] = insert[1] > e[1] ? insert[1] : e[1];
    }
    if (insert) {
        num = pushbackInterval(result, num, insert, *returnColumnSizes);
    }
    *returnSize = num;
    return result;
}

// @lc code=end

