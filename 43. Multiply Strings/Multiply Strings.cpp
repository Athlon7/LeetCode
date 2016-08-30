class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if(num1 == "0" || num2 == "0")
            return "0";
        
        string ans;
        int l1 = num1.size(), l2 = num2.size();
        vector<int> nums(l1 + l2 + 1, 0);
        stringstream convert;

        for(int i = 0;i < l1;++i)
        {
        	for(int j = 0;j < l2;++j)
        	{
        		nums[i + j] += (num1[l1 - i - 1] - '0') * (num2[l2 - j - 1] - '0');
        	}
        }

        for(int i = 0;i < l1 + l2;++i)
        {        	
        	if(nums[i] >= 10)
        	{
        		nums[i + 1] += nums[i] / 10;
        		nums[i] %= 10;
        	}        	
        }
        
        bool front = true;
        for(int i = l1 + l2;i >= 0;--i)
        {
        	if(front && nums[i] == 0)
        		continue;

        	front = false;
        	convert << nums[i];
        }

        convert >> ans;

        return ans;
    };
};