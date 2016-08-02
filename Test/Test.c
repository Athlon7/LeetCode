#include <string.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 从pos开始搜索s串看是否满足要求，有所有子串连起来的子串
int serch(char* s, char** words, int wordsSize, int length_w, int pos)
{
    int i, j, k, l, cnt = 0;
    short *flag;

    flag = (short*)calloc(wordsSize, sizeof(short));

    // 一共需要找wordSize个子串
    for(i = 0;i < wordsSize;i++)
    {
        // 若某一轮没有找到子串，则说明不正确，跳出循环
        if(cnt != i)
            break;
        for(j = 0;j < wordsSize;j++)
        {
            // 找到目标子串，开始检验子串是否完整
            if(flag[j] == 0 && words[j][0] == s[pos])
            {
                k = pos;
                l = 0;
                while(s[k] == words[j][l] && s[k] != '\0')
                {
                    k++;
                    l++;
                }
                if(words[j][l] == '\0')
                {
                    cnt++;
                    flag[j] = 1;
                    pos = k;
                    break;
                }
            }
        }
    }

    free(flag);
    if(cnt == wordsSize)
        return 1;
    return 0;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize)
{
    int length_s, length_w, length_total = 0,i, j, *ans, cnt = 0;

    *returnSize = 0;
    ans = (int*)malloc(sizeof(int));

    // 初始化length_w，保存子串长度，length_s保存s串长度，length_total保存所有子串的长度和
    length_w = strlen(words[0]);
    length_s = strlen(s);
    length_total = length_w * wordsSize;

    // 遍历s串
    for(i = 0;i < length_s - length_total + 1;i++)
    {
        for(j = 0;j < wordsSize;j++)
        {
            if(s[i] == words[j][0])
            {               
                // 找到任意子串的首字符，开启搜索
                if(serch(s, words, wordsSize, length_w, i))
                {
                    (*returnSize)++;
                    ans = (int*)realloc(ans, (*returnSize) * sizeof(int));
                    ans[cnt++] = i;
                    break;
                }
            }
        }
    }
    return ans;
}


void main()
{
	// struct ListNode* output;
	// struct ListNode** input;
	// struct ListNode t4 = {4, NULL}, t3 = {3, &t4},
	// 	t2 = {-2, &t3}, t1 = {1, &t2};

	// input = (struct ListNode**)malloc(sizeof(struct ListNode*) * 2);
	// input[0] = (struct ListNode*)malloc(sizeof(struct ListNode));
	// input[1] = (struct ListNode*)malloc(sizeof(struct ListNode));
	// input[0] = NULL;
	// input[1] = &t2;
    
    int input[] = {3, 2, 2, 3};
    int size;
    char** words = (char**)malloc(sizeof(char*) * 2);
    words[0] = (char*)malloc(sizeof(char) * 3);
    words[1] = (char*)malloc(sizeof(char) * 3);
    // words[2] = (char*)malloc(sizeof(char) * 4);
    words[0] = "ab";
    words[1] = "ba";
    // words[2] = "the";

	int* output = findSubstring("abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababab", words, 2, &size);
    getchar();
}