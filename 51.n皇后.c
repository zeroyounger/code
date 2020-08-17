/*
 * @lc app=leetcode.cn id=51 lang=c
 *
 * [51] N皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (70.71%)
 * Likes:    507
 * Dislikes: 0
 * Total Accepted:    56.1K
 * Total Submissions: 79.4K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: [
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一到七步，可进可退。（引用自
 * 百度百科 - 皇后 ）
 * 
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define maxn 1000
static int arr[maxn];
int checkValid(int *arr,int i,int depth) {
	int k;
	for(k=0;k<depth;k++){
		if(i == arr[k])           
			return 1;
		if (abs(arr[k] - i) == depth - k)
			return 1; 
	}
	return 0;
} 
void f(int n,char ***p,int *returnSize,int depth){
	int i,j,k;
	if ( depth == n){
		p[*returnSize] = (char **)malloc(sizeof(char *) * n);
		for( j = 0; j < n; j++){
			(p[*returnSize])[j] =(char *)malloc(sizeof(char)*(n+1));
			for( k = 0; k < n; k++)
				((p[*returnSize])[j])[k] = '.';
			((p[*returnSize])[j])[arr[j]] = 'Q';  
			((p[*returnSize])[j])[n] ='\0'; 
		}
		(*returnSize)++;
	}
	for( i = 0; i < n; i++){
		if (checkValid(arr,i,depth)){
			continue;  
		}else {
			arr[depth] = i;
			f(n,p,returnSize,depth+1);  
		}         
	}   
}
char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
	char ***p;
	int i;
	p = (char ***) malloc(sizeof(char **) * 1000);
	*returnSize = 0;
	f(n,p,returnSize,0); 
	*returnColumnSizes = (int *) malloc(sizeof(int)*(*returnSize));
	for ( i = 0; i <(*returnSize); i++)
		(*returnColumnSizes)[i] = n;
	return p;    
}


// @lc code=end

