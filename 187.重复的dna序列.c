/*
 * @lc app=leetcode.cn id=187 lang=c
 *
 * [187] 重复的DNA序列
 *
 * https://leetcode-cn.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (45.13%)
 * Likes:    110
 * Dislikes: 0
 * Total Accepted:    21.3K
 * Total Submissions: 47.3K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * 所有 DNA 都由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。在研究 DNA 时，识别 DNA
 * 中的重复序列有时会对研究非常有帮助。
 * 
 * 编写一个函数来查找目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * 输出：["AAAAACCCCC", "CCCCCAAAAA"]
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
size_t get_hash(char *str)
{//ensure strlen(str)>=10
    register size_t hash=0;
    for(int i=0;i<10;i++)
    {
        hash=hash*131+str[i];
    }
    return hash;
}
struct Hash{
    size_t val;//保存hash,相同的hash视为同一字符串
    bool save;//是否已经保存，用于去重
    struct Hash *next_hash;//链表处理hash冲突
};

char ** findRepeatedDnaSequences(char * s, int* returnSize){
    int hash_size=strlen(s)-9;
    char **ret=NULL;
    *returnSize=0;
    if(hash_size<2)return ret;
    struct Hash **hash_map=calloc(hash_size,sizeof(struct Hash *));
    for(int i=0;i<hash_size;i++)
    {
        size_t hash_key=get_hash(s+i);
        struct Hash *hash_node=hash_map[hash_key%hash_size];
        struct Hash * new_node=NULL;
        if(!hash_node)
        {
            new_node=(struct Hash *)malloc(sizeof(struct Hash));
            new_node->next_hash=NULL;
            new_node->val=hash_key;
            new_node->save=false;
            hash_map[hash_key%hash_size]=new_node;
        }
        else
        {
            while(hash_node)
            {
                if(hash_node->val==hash_key)
                {
                    if(!hash_node->save)
                    {
                        hash_node->save=true;
                        (*returnSize)++;
                        ret=(char **)realloc(ret,sizeof(char *)*(*returnSize));
                        ret[(*returnSize)-1]=(char *)calloc(11,sizeof(char));
                        strncpy(ret[(*returnSize)-1],s+i,sizeof(char)*10);
                        printf("%s\n",ret[(*returnSize)-1]);
                    }
                    break;
                }
                else
                {
                    if(!hash_node->next_hash)
                    {
                        new_node=(struct Hash *)malloc(sizeof(struct Hash));
                        new_node->next_hash=NULL;
                        new_node->val=hash_key;
                        new_node->save=false;
                        hash_node->next_hash=new_node;
                        break;
                    }
                    hash_node=hash_node->next_hash;
                }
            }
        }
    }
    for(int i=0;i<hash_size;i++)
    {
        struct Hash *hash=hash_map[i];
        while(hash)
        {
            struct Hash *tmp=hash;
            hash=hash->next_hash;
            free(tmp);
        }
    }
    free(hash_map);
    return ret;
}

// @lc code=end

