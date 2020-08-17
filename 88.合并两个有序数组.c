/*
 * @lc app=leetcode.cn id=88 lang=c
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (48.41%)
 * Likes:    592
 * Dislikes: 0
 * Total Accepted:    193.5K
 * Total Submissions: 399.7K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 
 * 
 * 示例:
 * 
 * 输入:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * 输出: [1,2,2,3,5,6]
 * 
 */

// @lc code=start


int comp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i=0;
    for(i=m;i<m+n;i++)
        nums1[i]=nums2[i-m];
    qsort(nums1,m+n,sizeof(int),comp);
}
// @lc code=end

