int removeElement(int* nums, int numsSize, int val)
{
    if(numsSize == 0)
    	return 0;

    int size = numsSize, i = 0, j = 0;

    while(i < numsSize)
    {
    	if(nums[i] == val)
    	{
    		i++;
    		size--;
    	}
    	else
    	{
    		nums[j++] = nums[i++];
    	}
    }

    return size;
}