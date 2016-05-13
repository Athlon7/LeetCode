/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** matrix(char** input, int* num, int* size, char** chart, int digit)
{
	int i, j;
	int cnt = 0;
	char** output;

	// 第一个数字
	if(*num == 0)
	{
		if(digit == 0)
		{
			output = (char**)malloc(sizeof(char*) * 1);			
			output[0] = (char*)malloc(sizeof(char) * 2);
			output[i][0] = ' ';
			output[i][1] = '\0';			
			*size = 1;
			
		}
		else if(digit == 7 || digit == 9)
		{
			output = (char**)malloc(sizeof(char*) * 4);
			for(i = 0;i < 4;i++)
				output[i] = (char*)malloc(sizeof(char) * 2);
			for(i = 0;i < 4;i++)
			{
				output[i][0] = chart[digit][i];
				output[i][1] = '\0';
			}
			*size = 4;
		}
		else
		{
			output = (char**)malloc(sizeof(char*) * 3);
			for(i = 0;i < 3;i++)
				output[i] = (char*)malloc(sizeof(char) * 2);
			for(i = 0;i < 3;i++)
			{
				output[i][0] = chart[digit][i];
				output[i][1] = '\0';
			}
			*size = 3;
		}

		*num = 1;
	}
	// 从第二个数字开始矩阵法
	else if(digit == 0)
	{
		output = (char**)malloc(sizeof(char*) * (*size));
		for(i = 0;i < *size;i++)
			output[i] = (char*)malloc(sizeof(char) * (*num + 2));
		for(i = 0;i < *size;i++)
		{
			strcpy(output[cnt], input[i]);
			output[cnt][*num] = ' ';
			output[cnt++][*num + 1] = '\0';
		}		
		(*num)++;
	}
	else if(digit == 7 || digit == 9)
	{
		output = (char**)malloc(sizeof(char*) * (*size * 4));
		for(i = 0;i < (*size * 4);i++)
			output[i] = (char*)malloc(sizeof(char) * (*num + 2));
		for(i = 0;i < *size;i++)
		{
			for(j = 0;j < 4;j++)
			{
				strcpy(output[cnt], input[i]);
				output[cnt][*num] = chart[digit][j];
				output[cnt++][*num + 1] = '\0';				
			}
		}
		*size *= 4;
		(*num)++;
	}
	else
	{
		output = (char**)malloc(sizeof(char*) * (*size * 3));
		for(i = 0;i < (*size * 3);i++)
			output[i] = (char*)malloc(sizeof(char) * (*num + 2));
		for(i = 0;i < *size;i++)
		{
			for(j = 0;j < 3;j++)
			{
				strcpy(output[cnt], input[i]);
				output[cnt][*num] = chart[digit][j];
				output[cnt++][*num + 1] = '\0';				
			}
		}
		*size *= 3;
		(*num)++;
	}
	if(input != NULL)
		free(input);
	return output;
}


char** letterCombinations(char* digits, int* returnSize)
{
    int length, sets, i, j, num = 0;
    char **ans, **in, temp = 'a';
    char **chart;

    if(digits == NULL)
    	return NULL;
    length = strlen(digits); 

    // 制作查找表
    chart = (char**)malloc(sizeof(char*) * 10);
    for(i = 0;i < 10;i++)
    {
    	chart[i] = (char*)malloc(sizeof(char) * 4);
    	for(j = 0;j < 4;j++)
    		chart[i][j] = 0;
    }
    
    for(i = 2;i < 10;i++)
    {
    	for(j = 0;j < 4;j++)
    	{
    		if(j == 3 && i != 7 && i != 9)
    			break;
    		chart[i][j] = temp++;
    	}
    }

    ans = NULL;
    for(i = 0;i < length;i++)
    {
    	in = ans;
    	ans = matrix(in, &num, returnSize, chart, (int)(digits[i] - 48));
    }
    return ans;
}