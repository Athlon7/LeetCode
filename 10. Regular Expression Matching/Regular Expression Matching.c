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
    	// .�����ֱ�ӹ�
    	if(p[j] == '.')
    	{
    		i++;
    		j++;
    		continue;
    	}
    	// ��* ��*ǰ��ĸһ��
    	else if(p[j] == '*')
    	{
    		// *ǰ����.���������
    		if(p[j - 1] == '.')
    		{
    			// ���.*����û�ַ�����ֱ��ƥ��ɹ�
    			if(p[j + 1] == '\0')
    				return true;
    			// else if
    		}

    		// һ�����
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
    		// ���߲�һ�����Ǻ�����*������������϶�*����0�������������ַ�
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