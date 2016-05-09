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
    	// 右边短板，移动右边
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
    	// 左边短板，移动左边
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
    	// 两边一样时，都向内移动至下一个较高的
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