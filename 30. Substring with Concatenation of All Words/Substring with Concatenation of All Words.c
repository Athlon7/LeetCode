/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// ��pos��ʼ����s�����Ƿ�����Ҫ���������Ӵ����������Ӵ�
int serch(char* s, char** words, int wordsSize, int* length_w, int pos)
{
	int *flag, i, j, k, l, cnt = 0;

	flag = (int*)calloc(wordsSize, sizeof(int));

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
				while(s[k] == words[j][l])
				{
					k++;
					l++;
				}
				if(words[j][l] == '\0')
				{
					cnt++;
					flag[j] = 1;
					pos = k + 1;
				}
			}
		}
	}

	if(cnt == wordsSize)
		return 1;
	return 0;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize)
{
    int length_s, *length_w, length_total = 0,i, j, *ans, cnt = 0;

    length_w = (int*)calloc(wordsSize, sizeof(int));    
    *returnSize = 0;

    // ��ʼ��length_w�����������Ӵ����ȣ�length_s����s�����ȣ�length_total���������Ӵ��ĳ��Ⱥ�
    for(i = 0;i < wordsSize;i++)
    {
    	length_w[i] = strlen(words[i]);
    	length_total += length_w[i];
    }
    length_s = strlen(s);


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
    				ans = (int*)realloc(ans, *returnSize * sizeof(int));
    				ans[cnt++] = i;
    				break;
    			}
    		}
    	}
    }
    return ans;
}