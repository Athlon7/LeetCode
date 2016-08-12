class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int length = nums.size();

        for(int i = 0;i <length;++i)
        {
        	if(target == nums[i] || target < nums[i])
        		return i;
        }
        return length;
    }
};