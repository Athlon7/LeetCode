/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) 
{
    int *ans;
    int i, j;
    int flag = 0;

    ans = (int *)malloc(sizeof(int) * 2);
    for (i = 0;i < numsSize;i++)
    {
    	for (j = i + 1;j < numsSize;j++)
    	{
    		if(nums[i] + nums[j] == target)
    		{
    			ans[0] = i;
    			ans[1] = j;
    			flag = 1;
    			break;
    		}
    	}    	
    	if (flag) break;
    }
    return ans;
}