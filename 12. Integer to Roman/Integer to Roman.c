char* intToRoman(int num)
{
    char* ans;
    int i, temp;
    int cnt = 0;

    ans = (char *)malloc(sizeof(char) * 17);
    // 千位
    temp = (int)(num / 1000);
    for(i = 0;i < temp;i++)    
    	ans[cnt++] = 'M';
    // 百位
    num = num % 1000;
    temp = (int)(num / 100);
    switch(temp)
    {
    	case 1:
    		ans[cnt++] = 'C';
    		break;
    	case 2: 
    		ans[cnt++] = 'C';
    		ans[cnt++] = 'C';
    		break;
    	case 3:
    		ans[cnt++] = 'C';
    		ans[cnt++] = 'C';
    		ans[cnt++] = 'C';
    		break;
    	case 4:
    		ans[cnt++] = 'C';
    		ans[cnt++] = 'D';
    		break;
    	case 5:
    		ans[cnt++] = 'D';
    		break;
    	case 6:
    		ans[cnt++] = 'D';
    		ans[cnt++] = 'C';
    		break;
    	case 7:
    		ans[cnt++] = 'D';
    		ans[cnt++] = 'C';
    		ans[cnt++] = 'C';
    		break;
    	case 8:
    		ans[cnt++] = 'D';
    		ans[cnt++] = 'C';
    		ans[cnt++] = 'C';
    		ans[cnt++] = 'C';
    		break;
    	case 9:
    		ans[cnt++] = 'C';
    		ans[cnt++] = 'M';
    		break;
    	default: break;
    }
    // 十位
    num = num % 100;
    temp = (int)(num / 10);
    switch(temp)
    {
    	case 1:
    		ans[cnt++] = 'X';
    		break;
    	case 2: 
    		ans[cnt++] = 'X';
    		ans[cnt++] = 'X';
    		break;
    	case 3:
    		ans[cnt++] = 'X';
    		ans[cnt++] = 'X';
    		ans[cnt++] = 'X';
    		break;
    	case 4:
    		ans[cnt++] = 'X';
    		ans[cnt++] = 'L';
    		break;
    	case 5:
    		ans[cnt++] = 'L';
    		break;
    	case 6:
    		ans[cnt++] = 'L';
    		ans[cnt++] = 'X';
    		break;
    	case 7:
    		ans[cnt++] = 'L';
    		ans[cnt++] = 'X';
    		ans[cnt++] = 'X';
    		break;
    	case 8:
    		ans[cnt++] = 'L';
    		ans[cnt++] = 'X';
    		ans[cnt++] = 'X';
    		ans[cnt++] = 'X';
    		break;
    	case 9:
    		ans[cnt++] = 'X';
    		ans[cnt++] = 'C';
    		break;
    	default: break;
    }
    // 个位
    temp = num % 10;
    switch(temp)
    {
    	case 1:
    		ans[cnt++] = 'I';
    		break;
    	case 2: 
    		ans[cnt++] = 'I';
    		ans[cnt++] = 'I';
    		break;
    	case 3:
    		ans[cnt++] = 'I';
    		ans[cnt++] = 'I';
    		ans[cnt++] = 'I';
    		break;
    	case 4:
    		ans[cnt++] = 'I';
    		ans[cnt++] = 'V';
    		break;
    	case 5:
    		ans[cnt++] = 'V';
    		break;
    	case 6:
    		ans[cnt++] = 'V';
    		ans[cnt++] = 'I';
    		break;
    	case 7:
    		ans[cnt++] = 'V';
    		ans[cnt++] = 'I';
    		ans[cnt++] = 'I';
    		break;
    	case 8:
    		ans[cnt++] = 'V';
    		ans[cnt++] = 'I';
    		ans[cnt++] = 'I';
    		ans[cnt++] = 'I';
    		break;
    	case 9:
    		ans[cnt++] = 'I';
    		ans[cnt++] = 'X';
    		break;
    	default: break;
    }

    ans[cnt++] = '\0';
    return ans;
}