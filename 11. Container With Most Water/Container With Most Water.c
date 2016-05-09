int maxArea(int* height, int heightSize)
{
    int i, j;
    int Area = 0;
    int lower, temp;

    i = 0;
    j = heightSize - 1;
    Area = ((height[i] > height[j])?height[j]:height[i]) * (j - i);  

    while(i != j)
    {
    	// �ұ߶̰壬�ƶ��ұ�
    	if(height[i] > height[j])
    	{
    		lower = height[j];
    		if(height[--j] > lower)
    		{
    			temp = ((height[i] > height[j])?height[j]:height[i]) * (j - i);
    			if(temp > Area)    				
    				Area = temp;			
    		}    		
    	}
    	// ��߶̰壬�ƶ����
    	else if(height[i] < height[j])
    	{
    		lower = height[i];
    		if(height[++i] > lower)
    		{
    			temp = ((height[i] > height[j])?height[j]:height[i]) * (j - i);
    			if(temp > Area)
    				Area = temp;	
    		}
    	}
    	// ����һ��ʱ���������ƶ�����һ���ϸߵ�
    	else
    	{
    		lower = height[i];
    		while(i != j)    		
    			if(height[i] <= lower)
    				i++;
    			else
    				break;
    		lower = height[j];
    		while(i != j)
    			if(height[j] <= lower)
    				j--;
    			else
    				break;
    		temp = ((height[i] > height[j])?height[j]:height[i]) * (j - i);
    		if(temp > Area)    	
    			Area = temp;
    	}
    }
    return Area;
}