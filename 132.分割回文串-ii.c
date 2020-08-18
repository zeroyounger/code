/*
 * @lc app=leetcode.cn id=132 lang=c
 *
 * [132] 分割回文串 II
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (43.38%)
 * Likes:    181
 * Dislikes: 0
 * Total Accepted:    14.3K
 * Total Submissions: 32.9K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 * 
 * 返回符合要求的最少分割次数。
 * 
 * 示例:
 * 
 * 输入: "aab"
 * 输出: 1
 * 解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
 * 
 * 
 */

// @lc code=start


int isPal(char * s, int size){
    int left=0,right=size-1;
    while(left<right)
        if(s[left++]!=s[right--])
            return 0;
    return 1;
}
int minCut(char * s){
    int n = strlen(s);
    int *f=(int*)malloc(sizeof(int)*(n+1));
    char *tmp=malloc(sizeof(char)*n);
    memset(tmp,0,n);
    f[0]=-1;
    for(int i=1;i<=n;i++){
        f[i]=i;
        for(int j=0;j<i;j++){
            strncpy(tmp,s+j,i-j);
            if(isPal(tmp,i-j))
                f[i]=fmin(f[j]+1,f[i]);
        }
    }
    free(tmp);
    return f[n];
}
// @lc code=end

