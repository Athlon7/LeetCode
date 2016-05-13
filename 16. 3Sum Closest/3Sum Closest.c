void sort(int* nums, int left, int right)
{
	if(left >= right)
		return;

	int temp;
	int i = left;
	int j = right;

	temp = nums[left];
	while(i < j)
	{
		while(i < j && nums[j] >= temp)
			j--;
		nums[i] = nums[j];
		while(i < j && nums[i] <= temp)
			i++;
		nums[j] = nums[i];		
	}
	nums[i] = temp;

	sort(nums, left, i - 1);
	sort(nums, i + 1, right); 
}

int threeSumClosest(int* nums, int numsSize, int target)
{
    int temp, i, j, k, ans;
    int hold = 99999;

    sort(nums, 0, numsSize - 1);

    i = 0;
    while(i < numsSize)
    {    	   	
    	j = i + 1;    	
    	k = numsSize - 1;
    	while(k > j)
    	{
    		temp = nums[i] + nums[j] + nums[k];
    		if(abs(temp - target) < hold)
    		{
    			ans = temp;
    			hold = abs(temp - target);
    		}
    		if(temp == target)
    			return ans;
    		if(temp < target)
    		{
    			while(nums[j + 1] == nums[j])
    				j++;
    			j++;
    		}    			
    		else
    		{
    			while(nums[k - 1] == nums[k])
    				k--;
    			k--;
    		}
    	}
    	
    	while(nums[i + 1] == nums[i])
    		i++;
    	i++;
    }

    return ans;
}