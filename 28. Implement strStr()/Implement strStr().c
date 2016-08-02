 int strStr(char* haystack, char* needle)
{
	if(haystack[0] == '\0')
		if(needle[0] == '\0')
			return 0;
		else
			return -1;
	else if(needle[0] == '\0')
		return 0;

	int i, j, k, index = -1, length_h, length_n;

	length_h = strlen(haystack);
	length_n = strlen(needle);

	if(length_n > length_h)
		return -1;

	for(i = 0;i < length_h - length_n + 1;i++)
	{
		if(haystack[i] == needle[0])
		{
			index = i;
			k = i;
			j = 0;
			while(haystack[k] == needle[j] && haystack[k] != '\0')
			{
				k++;
				j++;
			}
			if(needle[j] == '\0')
			{
				return index;
			}			
		}		
	}

	return -1;
}