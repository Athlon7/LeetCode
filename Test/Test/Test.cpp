#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

char* longestCommonPrefix(char** strs, int strsSize)
{
	int i, j, flag;
	char* ans;
	int cnt = 0;
	char temp;

	j = 0;
	while (1)
	{
		if (strs[0][j] == '\0')
			break;
		temp = strs[0][j];
		flag = 0;
		for (i = 1;i < strsSize;i++)
		{
			if (strs[i][j] != temp)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
		else
		{
			cnt++;
			j++;
		}
	}

	ans = (char *)malloc(sizeof(char) * (cnt + 1));
	for (i = 0;i < cnt;i++)
		ans[i] = strs[0][i];
	ans[i] = '\0';

	return ans;
}

void main()
{
	char* input = "1";
	char* output;
	int num = 1;

	output = longestCommonPrefix(&input, num);
	cout << output;
	getchar();
}