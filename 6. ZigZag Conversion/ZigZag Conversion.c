char* convert(char* s, int numRows)
{
	int length;
	int i, j, cnt;
	char *ans;

	length = strlen(s);
	if (numRows == 1)
		return s;
	ans = (char *)malloc(sizeof(char) * (length + 1));
	cnt = 0;
	for (i = 0;i <numRows;i++)
	{
		j = i;
		while (j < length)
		{
			if (i == 0)
			{
				ans[cnt++] = s[j];
				j = j + (numRows - 1 - i) * 2;
				if (j >= length)
					break;
			}
			else if (i == numRows - 1)
			{
				ans[cnt++] = s[j];
				j = j + (i - 0) * 2;
				if (j >= length)
					break;
			}
			else
			{
				ans[cnt++] = s[j];
				j = j + (numRows - 1 - i) * 2;
				if (j >= length)
					break;
				ans[cnt++] = s[j];
				j = j + (i - 0) * 2;
				if (j >= length)
					break;
			}
		}
	}
	ans[cnt] = '\0';
	return ans;
}