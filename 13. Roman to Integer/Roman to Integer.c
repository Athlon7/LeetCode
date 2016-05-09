void thousand(char* s, int* i, int* ans)
{
	int temp = 0;

	while(s[*i] == 'M')
	{
		temp++;
		(*i)++;
	}

	*ans = *ans + temp * 1000;
}

void hundred(char* s, int* i, int* ans)
{
	int temp = 0;

	if(s[*i] == 'C')
	{
		if(s[*i + 1] == 'M')
		{
			*i = *i + 2;
			temp = 9;
		}
		else if(s[*i + 1] == 'D')
		{
			*i = *i + 2;
			temp = 4;
		}
		else		
			while(s[*i] == 'C')
			{
				temp++;
				(*i)++;
			}
	}
	else
	{
		temp = 5;
		(*i)++;
		while(s[*i] == 'C')
		{
			temp++;
			(*i)++;
		}
	}

	*ans = *ans + temp * 100;	
}

void ten(char* s, int* i, int* ans)
{
	int temp = 0;

	if(s[*i] == 'X')
	{
		if(s[*i + 1] == 'C')
		{
			*i = *i + 2;
			temp = 9;
		}
		else if(s[*i + 1] == 'L')
		{
			*i = *i + 2;
			temp = 4;
		}
		else		
			while(s[*i] == 'X')
			{
				temp++;
				(*i)++;
			}
	}
	else
	{
		temp = 5;
		(*i)++;
		while(s[*i] == 'X')
		{
			temp++;
			(*i)++;
		}
	}

	*ans = *ans + temp * 10;	
}

void bits(char* s, int* i, int* ans)
{
	int temp = 0;

	if(s[*i] == 'I')
	{
		if(s[*i + 1] == 'X')
		{
			*i = *i + 2;
			temp = 9;
		}
		else if(s[*i + 1] == 'V')
		{
			*i = *i + 2;
			temp = 4;
		}
		else		
			while(s[*i] == 'I')
			{
				temp++;
				(*i)++;
			}
	}
	else
	{
		temp = 5;
		(*i)++;
		while(s[*i] == 'I')
		{
			temp++;
			(*i)++;
		}
	}

	*ans = *ans + temp;	
}

int romanToInt(char* s)
{
	int ans = 0;
	int i = 0;	
	
	while(s[i] != '\0')
	{
		switch(s[i])
		{
			case 'M': thousand(s, &i, &ans); break;
			case 'D': hundred(s, &i, &ans); break;
			case 'C': hundred(s, &i, &ans); break;
			case 'X': ten(s, &i, &ans); break;
			case 'L': ten(s, &i, &ans); break;
			case 'V': bits(s, &i, &ans); break;
			case 'I': bits(s, &i, &ans); break;
			default: break;
		}
	}

	return ans;
}