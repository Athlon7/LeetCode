bool isMatch(char* s, char* p)
{
    int length_s, length_p, i, j;
    int len_flag = 0;
    char left, right;

    length_s = strlen(s);
    length_p = strlen(p);

    // unequal lenth
    if(length_s != length_p)
    {
    	for(i = 0;i < length_p;i++)    	
    		if(p[i] == '*')
    		{
    			len_flag = 1;
    			break;
    		}
    	if(!len_flag)
    		return false;
    }
    
    i = 0;
    j = 0;
    while(p[j] != '\0')
    {
    	// .的情况直接过
    	if(p[j] == '.')
    	{
    		i++;
    		j++;
    		continue;
    	}
    	// 有* 且*前字母一致
    	else if(p[j] == '*')
    	{
    		// *前面是.的特殊情况
    		if(p[j - 1] == '.')
    		{
    			// 如果.*后面没字符，则直接匹配成功
    			if(p[j + 1] == '\0')
    				return true;
    			// else if
    		}

    		// 一般情况
    		left = p[j - 1];
    		right = p[j + 1];
    		while(s[i] == left)
    		{
    			i++;
    		}
    		j++;
    		while(p[j] == s[i - 1])
    		{
    			j++;
    		}
    		continue;
    	}
    	else if(s[i] != p[j])
    	{
    		// 两者不一样但是后面有*的情况，可以认定*代表0，跳过这两个字符
    		if(p[j + 1] == '*')
    		{
    			j = j + 2;
    			continue;
    		}
    		return false;
    	}
    	i++;
    	j++;
    }
    if(s[i] != p[j])
    {    	
    	return false;
    }
    return true;
}