/*
 * @lc app=leetcode.cn id=54 lang=c
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (40.97%)
 * Likes:    460
 * Dislikes: 0
 * Total Accepted:    75.1K
 * Total Submissions: 183.2K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 输出: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
	* returnSize=0;
	int r=matrixSize,c=* matrixColSize;
    if(matrix==NULL || r==0) return matrix;
	int sum=matrixSize*(*matrixColSize);
    int* ret=(int*)calloc(sum+1,sizeof(int));
	int ceng=fmin(r,c);
	if(ceng%2==0) ceng=ceng/2;
	else ceng=ceng/2+1;//确定层数的时候分奇偶
	int i;//当前层数
	int h,l;//汉语拼音 行 列，之前r c已经用过了
	for(i=0; i<ceng; i++) {//整个转一圈，我得判断里加了个(* returnSize)<sum，这样省的越界。一圈一圈。
		h=i,l=i;
		while((l<c-i)&&(* returnSize)<sum) {
			ret[(* returnSize)++]=matrix[h][l++];
		}
		h++;
		l--;
		while((h<r-i)&&(* returnSize)<sum) {
			ret[(* returnSize)++]=matrix[h++][l];
		}
		l--;
		h--;
		while((l>i)&&(* returnSize)<sum) {
			ret[(* returnSize)++]=matrix[h][l--];
		}
		while((h>i)&&(* returnSize)<sum) {
			ret[(* returnSize)++]=matrix[h--][l];
		}
	}
	ret[* returnSize]='\0';
	return ret;
}


// @lc code=end

