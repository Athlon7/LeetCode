char* longestCommonPrefix(char** strs, int strsSize)
{
    int i, j, flag;
    char* ans;
    int cnt = 0;    

    if(strs == NULL || *strs == NULL)
    	return "";

    j = 0;
    while(1)
    {
    	if(strs[0][j] == '\0')
    		break;    	
    	flag = 0;
    	for(i = 1;i < strsSize;i++)
    	{
    		if(strs[i][j] != strs[0][j])
    		{
    			flag = 1;
    			break;
    		}
    	}
    	if(flag)
    		break;
    	else
    	{
    		cnt++;
    		j++;
    	}
    }

    ans = (char *)malloc(sizeof(char) * (cnt + 1));
    for(i = 0;i < cnt;i++)
    	ans[i] = strs[0][i];
    ans[i] = '\0';

    return ans;
}