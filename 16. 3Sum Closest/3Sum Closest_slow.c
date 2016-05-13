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
    	while(j < numsSize)
    	{
    		temp = nums[i] + nums[j];
    		k = numsSize - 1;
    		while(k > j)
    		{
    			if(abs(temp + nums[k] - target) < hold)
    			{
    				ans = temp + nums[k];
    				hold = abs(temp + nums[k] - target);
    			}
    			if(temp + nums[k] < target)
    				break;
    			while(nums[k - 1] == nums[k])
    				k--;
    			k--;
    		}
    		while(nums[j + 1] == nums[j])
    			j++;
    		j++;
    	}
    	while(nums[i + 1] == nums[i])
    		i++;
    	i++;
    }

    return ans;
}