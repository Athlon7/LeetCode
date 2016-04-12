/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) 
{
    int *ans;
    int i, j, lenth;
    int flag = 0;

    ans = (int *)malloc(sizeof(int) * 2);
    //lenth = sizeof(nums) / sizeof(nums[0]);
    for (i = 0;i < numsSize;i++)
    {
    	//if (nums[i] > target)
    	//	continue;
    	//else
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
    	}
    	if (flag) break;
    }
    return ans;
}
void main()
{
	int input[3] = { 3, 2, 4 };
	int target = 6;
	int *answer;

	answer = twoSum(input, target);
}