/*
 * @lc app=leetcode.cn id=352 lang=c
 *
 * [352] 将数据流变为多个不相交区间
 *
 * https://leetcode-cn.com/problems/data-stream-as-disjoint-intervals/description/
 *
 * algorithms
 * Hard (55.00%)
 * Likes:    33
 * Dislikes: 0
 * Total Accepted:    2.3K
 * Total Submissions: 4.2K
 * Testcase Example:  '["SummaryRanges","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals"]\n' +
  '[[],[1],[],[3],[],[7],[],[2],[],[6],[]]'
 *
 * 给定一个非负整数的数据流输入 a1，a2，…，an，…，将到目前为止看到的数字总结为不相交的区间列表。
 * 
 * 例如，假设数据流中的整数为 1，3，7，2，6，…，每次的总结为：
 * 
 * [1, 1]
 * [1, 1], [3, 3]
 * [1, 1], [3, 3], [7, 7]
 * [1, 3], [7, 7]
 * [1, 3], [6, 7]
 * 
 * 
 * 
 * 
 * 进阶：
 * 如果有很多合并，并且与数据流的大小相比，不相交区间的数量很小，该怎么办?
 * 
 * 提示：
 * 特别感谢 @yunhong 提供了本问题和其测试用例。
 * 
 */

// @lc code=start



typedef struct {
    
} SummaryRanges;

/** Initialize your data structure here. */

SummaryRanges* summaryRangesCreate() {
    
}

void summaryRangesAddNum(SummaryRanges* obj, int val) {
  
}

int** summaryRangesGetIntervals(SummaryRanges* obj, int* retSize, int** retColSize) {
  
}

void summaryRangesFree(SummaryRanges* obj) {
    
}

/**
 * Your SummaryRanges struct will be instantiated and called as such:
 * SummaryRanges* obj = summaryRangesCreate();
 * summaryRangesAddNum(obj, val);
 
 * int** param_2 = summaryRangesGetIntervals(obj, retSize, retColSize);
 
 * summaryRangesFree(obj);
*/
// @lc code=end

