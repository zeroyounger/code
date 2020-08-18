/*
 * @lc app=leetcode.cn id=128 lang=c
 *
 * [128] 最长连续序列
 *
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (51.79%)
 * Likes:    498
 * Dislikes: 0
 * Total Accepted:    73.3K
 * Total Submissions: 141.6K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组，找出最长连续序列的长度。
 * 
 * 要求算法的时间复杂度为 O(n)。
 * 
 * 示例:
 * 
 * 输入: [100, 4, 200, 1, 3, 2]
 * 输出: 4
 * 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 */

// @lc code=start


int cmp(const void *a, const void *b) {
    int x=*(int *)a;
    int y=*(int *)b;
    if (x>y) return 1;
    if (x<y) return -1;
    return 0;
}
int longestConsecutive(int* nums, int numsSize){
    if (numsSize <= 1) return numsSize;
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    int max=1,cur=1;
    for(int i=0;i!=numsSize-1;i++){
        if(nums[i]+1==nums[i+1]){
            cur++;
            if(max<cur) max=cur;
            continue;
        }
        if(nums[i]==nums[i+1])
            continue;
        cur=1;
    }
    return max;
}


// @lc code=end

