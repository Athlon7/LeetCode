/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int** threeSum(int* nums, int numsSize, int* returnSize)
{
    int** ans;
    int* flag;
    int i, j, k, l, temp, repeat, array[3];

    // 如果输入不够3个，则无解，直接返回空
    if(numsSize < 3)
    	return NULL;

    flag = (int*)malloc(sizeof(int) * numsSize);
    memset(flag, 0, sizeof(int));
    ans = (int**)malloc(sizeof(int*) * 100);
    for(i = 0;i < 100;i++)
    	ans[i] = (int*)malloc(sizeof(int) * 3);
    *returnSize = 0;

    for(i = 0;i < numsSize;i++)
    {
    	// if(flag[i] == 1)
    	// 	continue;
    	// found = 0;
    	for(j = i + 1;j < numsSize;j++)
    	{
    		// if(flag[j] == 1)
    		// 	continue;
    		temp = nums[i] + nums[j];
    		for(k = j + 1;k < numsSize;k++)
    		{
    			// if(flag[k] == 1)
    			// 	continue;
    			if(nums[k] == -temp)
    			{
    				// flag[i] = 1;
    				// flag[j] = 1;
    				// flag[k] = 1;
    				if(nums[i] < nums[j])
    				{
    					if(nums[i] < nums[k])
    					{
    						if(nums[j] < nums[k])
    						{
    							array[0] = nums[i];
    							array[1] = nums[j];
    							array[2] = nums[k];
    						}
    						else
    						{
    							array[0] = nums[i];
    							array[1] = nums[k];
    							array[2] = nums[j];
    						}
    					}
    					else
    					{
    						array[0] = nums[k];
    						array[1] = nums[i];
    						array[2] = nums[j];
    					}
    				}
    				else
    				{
    					if(nums[i] > nums[k])
    					{
    						if(nums[j] > nums[k])
    						{
    							array[0] = nums[k];
    							array[1] = nums[j];
    							array[2] = nums[i];
    						}
    						else
    						{
    							array[0] = nums[j];
    							array[1] = nums[k];
    							array[2] = nums[i];
    						}
    					}
    					else
    					{
    						array[0] = nums[j];
    						array[1] = nums[i];
    						array[2] = nums[k];
    					}
    				}
    				for(l = 0;l < *returnSize;l++)
    					if(array[0] == ans[*returnSize][0] && array[1] == ans[*returnSize][1] && array[2] == ans[*returnSize][2])
    						repeat = 1;
    				if(!repeat)
    				{
    					ans[*returnSize][0] = array[0];
    					ans[*returnSize][1] = array[1];
    					ans[*returnSize][2] = array[2];
    					(*returnSize)++;
    				}
    				break;
    			}
    		}
    		// if(found)
    		// 	break;
    	}
    }
    return ans;
}