/*
 * @lc app=leetcode.cn id=81 lang=c
 *
 * [81] 搜索旋转排序数组 II
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (35.78%)
 * Likes:    204
 * Dislikes: 0
 * Total Accepted:    36.7K
 * Total Submissions: 102.5K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
 * 
 * 编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。
 * 
 * 示例 1:
 * 
 * 输入: nums = [2,5,6,0,0,1,2], target = 0
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [2,5,6,0,0,1,2], target = 3
 * 输出: false
 * 
 * 进阶:
 * 
 * 
 * 这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
 * 这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？
 * 
 * 
 */

// @lc code=start


bool search(int* nums, int numsSize, int target){
    if(numsSize<=0||(numsSize==1&&nums[0]!=target))
        return false;
    int l=0,h=numsSize-1,m;
    while(l<=h){
        m=(l+h)/2;
        if(nums[m]==target)
            return true;
        if(nums[m]==nums[l]&&nums[m]==nums[h]){
            l++;
            h--;
        }
        else if(target>nums[m]){
            if(nums[m]<=nums[h]&&target>nums[h])
                h=m-1;
            else l=m+1;
        }
        else if(target<nums[m]){
            if(nums[m]>=nums[l]&&target<nums[l])
                l=m+1;
            else h=m-1;
        }
    }
    return false;
}


// @lc code=end

