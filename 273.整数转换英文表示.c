/*
 * @lc app=leetcode.cn id=273 lang=c
 *
 * [273] 整数转换英文表示
 *
 * https://leetcode-cn.com/problems/integer-to-english-words/description/
 *
 * algorithms
 * Hard (28.26%)
 * Likes:    90
 * Dislikes: 0
 * Total Accepted:    6.7K
 * Total Submissions: 23.6K
 * Testcase Example:  '123'
 *
 * 将非负整数转换为其对应的英文表示。可以保证给定输入小于 2^31 - 1 。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: "One Hundred Twenty Three"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 12345
 * 输出: "Twelve Thousand Three Hundred Forty Five"
 * 
 * 示例 3:
 * 
 * 输入: 1234567
 * 输出: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 * 
 * 示例 4:
 * 
 * 输入: 1234567891
 * 输出: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven
 * Thousand Eight Hundred Ninety One"
 * 
 */

// @lc code=start


 const char *ones[]={
"","enO ","owT ","eerhT ","ruoF ","eviF ","xiS ","neveS ","thgiE ","eniN ","neT ","nevelE ","evlewT ","neetrihT ","neetruoF ","neetfiF ","neetxiS ","neetneveS ","neethgiE ","neeteniN ",};

const char * tens[]={"","neT ","ytnewT ","ytrihT ","ytroF ","ytfiF ","ytxiS ","ytneveS ","ythgiE ","yteniN ",};
const char *thous[]={"","dnasuohT ","noilliM ","noilliB "};
const char *hundred = "derdnuH ";
char zero[] ="Zero";
void reverse_str(char * str,int len)
{
     char tmp,*ptr = str+len -1;
     while(str < ptr)
     {
        tmp = *str;
        *(str++) = *ptr;
        *(ptr--) = tmp;
    }
}
 int copy_str(const char * str,char * ret,int index)
{
    const char *ptr = str;
    while(*ptr)
        ret[index++] = *(ptr++);
    return index ;
}

char ret[512];/// result to return

char* numberToWords(int num) {
    if(!num) return zero;
    int index = 0,tmp;
    for(int i = 0; num; i++)
    {
        if(num%1000)
            index = copy_str(thous[i],ret,index); 
        tmp = num%100;num/=100;
        if(tmp < 20)
            index = copy_str(ones[tmp],ret,index); 
        else 
        {
            index = copy_str(ones[tmp%10],ret,index);
            index = copy_str(tens[tmp/10],ret,index);
        }
        tmp = num % 10;num /= 10;
        if(tmp)
        {
            index = copy_str(hundred,ret,index);
            index = copy_str(ones[tmp],ret,index);
        }
    }
    ret[--index] = '\0';
    reverse_str(ret,index);
    return ret;
}


// @lc code=end

