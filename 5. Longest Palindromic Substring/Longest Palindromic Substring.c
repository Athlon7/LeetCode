int serchstring(char *ptr, char *ptr1, int cnt, int max, char *ans, char* s)
{
	char *left, *right;
	char temp = '\0';
	int i;

	left = ptr;
	right = ptr1;

	while(left != s)
	{
		left--;
		right++;
		if(*right == '\0')
		{
			left++;
			right--;
			break;
		}
		if(*right != *left)
		{
			left++;
			right--;
			break;
		}
		cnt = cnt + 2;
	}

	if(cnt > max)
	{
		for(i = 0;i < cnt;i++)
		{
			ans[i] = *left;
			left++;
		}
		ans[i] = '\0';

		return cnt;
	}
	
	return max;	
}

char* longestPalindrome(char* s)
{
    char *ans;
    char *ptr, *ptr1;
    int max = 0;
    int samecnt;

    if(strlen(s) == 1)
    	return s;
    ans = (char *)malloc(sizeof(char) * 1000);
    ptr = s;
    while(*ptr != '\0')
    {
    	ptr1 = ptr + 1;
    	if(*ptr == *ptr1)
    	{
    		samecnt = 1;
    		while(*ptr == *ptr1)
    		{
    			ptr1++;
    			samecnt++;
    		}
    		ptr1--;
    		max = serchstring(ptr, ptr1, samecnt, max, ans, s);
    	}
    	else
    	{
    		ptr1++;
    		if(*ptr == *ptr1)
    			max = serchstring(ptr, ptr1, 3, max, ans, s);
    	}
    	ptr++;
    }

    return ans;
}


