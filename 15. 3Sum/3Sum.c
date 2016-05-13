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

int** threeSum(int* nums, int numsSize, int* returnSize)
{
    int i, j, k, temp;
    int **ans;

    // 如果输入不够3个，则无解，直接返回空
    if(numsSize < 3)
    	return NULL;
    ans = (int**)malloc(sizeof(int*) * 1000);
    for(i = 0;i < 1000;i++)
    	ans[i] = (int*)malloc(sizeof(int) * 3);
    *returnSize = 0;

    sort(nums, 0, numsSize - 1);

    i = 0;
    while(nums[i] <= 0)
    {    	   	
    	j = i + 1;    	
    	k = numsSize - 1;
    	while(k > j)
    	{
    		temp = nums[i] + nums[j] + nums[k];
    		if(temp == 0)
    		{
    			ans[*returnSize][0] = nums[i];
    			ans[*returnSize][1] = nums[j];
    			ans[*returnSize][2] = nums[k];
    			(*returnSize)++;    			
    		}
    		if(temp <= 0)
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