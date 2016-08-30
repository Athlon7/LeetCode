class Solution
{
public:
    int jump(vector<int>& nums)
    {               
        int cnt = 0, i = 0, temp_value, temp_index;
        if(nums.size() == 1)
        	return 0;

        while(nums[i] < nums.size() - i - 1)
        {        	
        	temp_value = 0;
        	for(int j = i + 1;j <= i + nums[i];++j)
        	{
        		if(nums[j] + j - i > temp_value)
        		{
        			temp_value = nums[j] + j - i;
        			temp_index = j;
        		}
        	}        	

        	i = temp_index;
        	++cnt;
        }
        return ++cnt;
    }
};