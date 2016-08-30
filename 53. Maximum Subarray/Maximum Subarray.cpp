class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int temp = 0, max = 0;

        for(auto i : nums)
        {
        	temp += i;
        	if(temp > max)
        		max = temp;
        	if(temp < 0)
        		temp = 0;
        }
        return max;
    }
};