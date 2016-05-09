int lengthOfLongestSubstring(char* s)
{
    int length, i, max, temp;
    char *head, *ptr;
    int flags[200];

    //init
    length = strlen(s);
    head = s;
    ptr = s;
    memset(flags, 0, sizeof(int) * 200);
    flags[*head] = 1;
    temp = 1;
    max = 1;
    
    //empty string
    if(length == 0)
    {
    	return 0;
    }

    //serch for longest substring
    while(1)
    {
    	ptr++;
    	if(*ptr == '\0')
    		break;
    	temp++;
    	//new char is not repeated
    	if(flags[*ptr] == 0)
    	{
    		flags[*ptr] = 1;    		
    		if(temp > max)
    			max = temp;
    	}
    	//repeated
    	else
    	{
    		while(flags[*ptr] == 1)
    		{
    			flags[*head] = 0;
    			head++;
    			temp--;
    		}
    		flags[*ptr] = 1;
    	}
    }
    return max;
}