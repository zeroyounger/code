/*
 * @lc app=leetcode.cn id=31 lang=c
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (34.37%)
 * Likes:    612
 * Dislikes: 0
 * Total Accepted:    81.8K
 * Total Submissions: 238.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 
 * 必须原地修改，只允许使用额外常数空间。
 * 
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start


int comp(const void* a,const void* b){
    return *(int *)a - *(int *)b;
}

void nextPermutation(int* nums, int numsSize) {
    //判断是不是最大排列
    int i,head;
    for(i=numsSize-1;i>=1;i--){
        if(nums[i-1]<nums[i])break;
    }
    if(i==0){
        //已经是最大排列,返回升序
        qsort(nums,numsSize,sizeof(int),comp);
        return;
    }else{
        //找到了领头点，从领头+1找略大的值
        head = i-1;
        int min = 99999;
        int index = 0;
        
        for(i=head+1;i<numsSize;i++){
            if(nums[i]>nums[head] && (nums[i]-nums[head]) < min){
                min = nums[i]-nums[head];
                index = i;
            }
        }
        //交换nums[head]和nums[index];
        int tmp;
        tmp = nums[head];
        nums[head] = nums[index];
        nums[index] = tmp;
        //如果head不是倒数第二个，那么将head后面的升序
        if(head!=numsSize-2)qsort(nums+head+1,numsSize-head-1,sizeof(int),comp);
        return;
    }
}
// @lc code=end

