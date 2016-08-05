class Solution
{
public:
    int binSearch(vector<int> &nums, int target, int left, int right)
    {
    	int i = left, j = right, mid;

    	while(i <= j)
    	{
    		mid = (i + j) / 2;
    		if(nums[mid] == target)
    			return mid;
    		else if(target > nums[mid])
    			i = mid + 1;
    		else if(target < nums[mid])
    			j = mid - 1;
    	}
    	return -1;
    }

    // 先折半然后再附近遍历寻找
    // vector<int> searchRange(vector<int>& nums, int target)
    // {
    //     int length = nums.size();
    //     int ans, i;
    //     vector<int> pos(2, -1);

    //     if((ans = binSearch(nums, target, 0, length - 1)) == -1)
    //     	return pos;
    //     else
    //     {
    //     	for(i = ans;i >= 0;--i)
    //     	{
    //     		if(nums[i] != target)
    //     			break;
    //     	}
    //     	pos[0] = i + 1;
    //     	for(i = ans;i < length;++i)
    //     		if(nums[i] != target)
    //     			break;
    //     	pos[1] = i - 1;
    //     }
    //     return pos;
    // }
    // 
    
    // 始终折半
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int length = nums.size();
        int ans, i, front = 0, rare = 0;
        vector<int> pos(2, -1);

        if((ans = binSearch(nums, target, 0, length - 1)) == -1)
        	return pos;
        else
        {
        	int front_right = ans - 1, rare_left = ans + 1;
        	while(front != -1)
        	{
        		front = binSearch(nums, target, 0, front_right);
        		if(front != -1)
        		{
        			front_right = front - 1;
        			pos[0] = front;
        		}
        	}
        	while(rare != -1)
        	{
        		rare = binSearch(nums, target, rare_left, length -1);
        		if(rare != -1)
        		{
        			rare_left = rare - 1;
        			pos[1] = rare;
        		}
        	}
        }
        return pos;
    }
};