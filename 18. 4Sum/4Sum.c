/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 快速排序
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

int** fourSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i, j, k, l, temp, temp1;
    int **ans;

    // 如果输入不够4个，则无解，直接返回空
    if(numsSize < 4)
    	return NULL;
    ans = (int**)malloc(sizeof(int*) * 2000);
    for(i = 0;i < 2000;i++)
    	ans[i] = (int*)malloc(sizeof(int) * 4);
    *returnSize = 0;
    // 排序
    sort(nums, 0, numsSize - 1);

    if(4 * nums[0] > target)
    	return NULL;
    if(4 * nums[numsSize - 1] < target)
    	return NULL;

    i = 0;
    while(i < numsSize)
    {    	
    	if(4 * nums[i] > target)
    		break;
    	if(nums[i] + 3 * nums[numsSize - 1] < target)
    	{
    		while(nums[i + 1] == nums[i])
    			i++;
    		i++;
    		continue;
    	}
    	j = i + 1;
    	while(j < numsSize)
    	{
    		temp = nums[i] + nums[j];
    		if(temp + 2 * nums[j] > target)
    			break;
    		if(temp + 2 * nums[numsSize - 1] < target)
    		{
    			while(nums[j + 1] == nums[j])
    				j++;
    			j++;
    			continue;
    		}
    		k = j + 1;
    		l = numsSize - 1;
    		while(k < l)
    		{    			
    			temp1 = target - temp;
    			if(2 * nums[k] > temp1 || 2 * nums[l] < temp1)
    				break;
    			if(nums[k] + nums[l] == temp1)
    			{
    				ans[*returnSize][0] = nums[i];
    				ans[*returnSize][1] = nums[j];
    				ans[*returnSize][2] = nums[k];
    				ans[*returnSize][3] = nums[l];
    				(*returnSize)++;  
    				while(nums[k + 1] == nums[k])
    					k++;
    				k++;
    				while(nums[l - 1] == nums[l])
    					l--;
    				l--;
    			}
    			else if(nums[k] + nums[l] < temp1)
    			{
    				while(nums[k + 1] == nums[k])
    					k++;
    				k++;
    			}
    			else
    			{
    				while(nums[l - 1] == nums[l])
    					l--;
    				l--;
    			}
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