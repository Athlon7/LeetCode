int reverse(int x)
{
	char *s, *ans;
	int length, i, cnt, answer;
	char *max = "2147483647";
	int negative = 0;
	int flag = 0;

	s = (char *)malloc(sizeof(char) * 12);
	ans = (char *)malloc(sizeof(char) * 12);
	sprintf(s, "%d", x);
	//printf("%s\n", s);
	length = strlen(s);
	if (s[0] == '-')
	{
		negative = 1;
		if (length == 11)
			for (i = 10;i > 0;i--)
				if (s[i] < max[10 - i])
					break;
				else if (s[i] > max[10 - i])
					return 0;
	}
	else if (length == 10)
		for (i = 9;i > 0;i--)
			if (s[i] < max[9 - i])
				break;
			else if (s[i] > max[9 - i])
				return 0;

	cnt = 0;
	if (negative)
	{
		ans[0] = '-';
		cnt++;
		for (i = length - 1;i > 0;i--)
		{
			if (!flag)
			{
				if (s[i] != '0')
				{
					flag = 1;
					ans[cnt++] = s[i];
				}
			}
			else ans[cnt++] = s[i];
		}
	}
	else
		for (i = length - 1;i >= 0;i--)
		{
			if (!flag)
			{
				if (s[i] != '0')
				{
					flag = 1;
					ans[cnt++] = s[i];
				}
			}
			else ans[cnt++] = s[i];
		}
	ans[cnt] = '\0';

	answer = atoi(ans);

	return answer;
}