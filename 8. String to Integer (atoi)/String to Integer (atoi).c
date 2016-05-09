#define INT_MAX 2147483647
#define INT_MIN -2147483648

int myAtoi(char* str)
{
	int answer = 0;
	int length, *array, i;
	int negative = 1;
	int cnt = 0;
	int numflag = 0;
	int ratio = 1;
	int nonnumcnt = 0;
	int spaceflag = 0;
	int signflag = 0;
	int int_max[10] = { 2, 1, 4, 7, 4, 8, 3, 6, 4, 7 };
	int int_min[10] = { 2, 1, 4, 7, 4, 8, 3, 6, 4, 8 };

	length = strlen(str);
	if (length == 0)
		return 0;
	array = (int *)malloc(sizeof(int) * length);
	memset(array, 0, sizeof(int) * length);

	//scan for format error
	for (i = 0;i < length;i++)
	{
		//check for spaces
		if (!spaceflag)
			if (str[i] == ' ')
				continue;
			else if ((str[i] >= 48 && str[i] <= 57) || str[i] == '+' || str[i] == '-')
				spaceflag = 1;
			else
				return 0;
			//Sign Bit		
			if (!signflag)
			{
				if (str[i] == '+')
				{
					signflag = 1;
					continue;
				}
				else if (str[i] == '-')
				{
					signflag = 1;
					negative = -1;
					continue;
				}
				else if (str[i] >= 48 && str[i] <= 57)
					signflag = 1;
				else
					return 0;

			}
			//number part
			if (!numflag)
			{
				if (str[i] >= 48 && str[i] <= 57)
				{
					array[cnt++] = (int)(str[i] - 48);
					numflag = 1;
					continue;
				}
				else
					return 0;
			}
			else
			{
				if (str[i] >= 48 && str[i] <= 57)
					array[cnt++] = (int)(str[i] - 48);
				else break;
			}

	}
	// overflow check
	if (cnt > 10)
		if (negative == 1)
			return INT_MAX;
		else
			return INT_MIN;
	else if (cnt == 10)
	{
		if (negative == 1)
		{
			for (i = 0;i < cnt;i++)
				if (array[i] > int_max[i])
					return INT_MAX;
				else if (array[i] < int_max[i])
					break;


		}
		else
			for (i = 0;i < cnt;i++)
				if (array[i] > int_min[i])
					return INT_MIN;
				else if (array[i] < int_min[i])
					break;

	}
	while (cnt > 0)
	{
		answer += array[--cnt] * ratio;
		ratio = ratio * 10;
	}
	answer = answer * negative;
	return answer;
}