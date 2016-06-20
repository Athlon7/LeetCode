#include <string.h>
#include <stdlib.h>

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

void DFS(char** ans, int* returnSize, int n, int left)
{
	static char temp[100] = {0};
	static int left_cnt = 0;
	static int right_need = 0;
	static int i = 0;
	int j;

	if(left)
	{
		left_cnt++;
		right_need++;
		temp[i++] = '(';
	}
	else
	{
		right_need--;
		temp[i++] = ')';
	}

	if(left_cnt == n)
	{
		if(right_need == 0)
		{
			for(j = 0;j < 2 * n;j++)			
				ans[*returnSize][j] = temp[j];
			(*returnSize)++;
			i--;
			right_need++;
			return;
		}
		else
			DFS(ans, returnSize, n, 0);
	}
	else
	{
		DFS(ans, returnSize, n, 1);
		if(right_need != 0)
			DFS(ans, returnSize, n, 0);
	}

	if(left)
	{
		left_cnt--;
		right_need--;
		i--;
		return;
	}
	else
	{
		right_need++;
		i--;
		return;
	}
}

char** generateParenthesis(int n, int* returnSize)
{
	char **ans;
	int i;

	ans = (char **)malloc(sizeof(char *) * 100);
	for (i = 0;i < n * n;i++)
		ans[i] = (char *)malloc(sizeof(char) * 2 * n);
	*returnSize = 0;

	DFS(ans, returnSize, n, 1);

	return ans;
}




 void main()
{
	int input = 5;
	char** output;
	int num = 0;	

	output = generateParenthesis(input, &num);
	getchar();
}