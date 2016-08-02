#include <string.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// ��pos��ʼ����s�����Ƿ�����Ҫ���������Ӵ����������Ӵ�
int serch(char* s, char** words, int wordsSize, int length_w, int pos)
{
    int i, j, k, l, cnt = 0;
    short *flag;

    flag = (short*)calloc(wordsSize, sizeof(short));

    // һ����Ҫ��wordSize���Ӵ�
    for(i = 0;i < wordsSize;i++)
    {
        // ��ĳһ��û���ҵ��Ӵ�����˵������ȷ������ѭ��
        if(cnt != i)
            break;
        for(j = 0;j < wordsSize;j++)
        {
            // �ҵ�Ŀ���Ӵ�����ʼ�����Ӵ��Ƿ�����
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

    // ��ʼ��length_w�������Ӵ����ȣ�length_s����s�����ȣ�length_total���������Ӵ��ĳ��Ⱥ�
    length_w = strlen(words[0]);
    length_s = strlen(s);
    length_total = length_w * wordsSize;

    // ����s��
    for(i = 0;i < length_s - length_total + 1;i++)
    {
        for(j = 0;j < wordsSize;j++)
        {
            if(s[i] == words[j][0])
            {               
                // �ҵ������Ӵ������ַ�����������
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