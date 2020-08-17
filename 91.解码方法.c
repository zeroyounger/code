/*
 * @lc app=leetcode.cn id=91 lang=c
 *
 * [91] 解码方法
 *
 * https://leetcode-cn.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (24.23%)
 * Likes:    474
 * Dislikes: 0
 * Total Accepted:    62.1K
 * Total Submissions: 256.3K
 * Testcase Example:  '"12"'
 *
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 * 
 * 示例 1:
 * 
 * 输入: "12"
 * 输出: 2
 * 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "226"
 * 输出: 3
 * 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
 * 
 * 
 */

// @lc code=start


int numDecodings(char * s) {
	if (s[0]=='0'||s[0]==0) return 0;
	int pre=1,curr=1;//dp[-1]=dp[0]=1
	for(int i=1;s[i]!=0;i++){
		int tmp=curr;
		if(s[i]=='0')
			if(s[i-1]=='1'||s[i-1]=='2') curr=pre;//dp[i]=dp[i-2]
			else return 0;
		else if(s[i-1]=='1'||s[i-1]=='2'&&s[i]>='1'&&s[i]<='6')
			curr=curr+pre;//dp[i]=dp[i-1]+dp[i-2]
		pre=tmp;
	}
	return curr;
}

// @lc code=end

