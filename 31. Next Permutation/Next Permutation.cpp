class Solution
{
public:
    void sort(vector<int> &nums, int left, int right)
    {
    	if(left >= right)
    		return;
    	int i, j, temp = 0;

    	i = left;
    	j = right;
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

    void nextPermutation(vector<int>& nums)
    {
        if(nums.size() <= 1)
        	return;
        int temp = 0;
        if(nums.size() == 2)
        {
        	temp = nums[0];
        	nums[0] = nums[1];
        	nums[1] = temp;
        	return;
        }
        
        size_t n = nums.size();
        bool *flag = new bool[n]();
        int pos = -1;

        for(int i = 0;i < n - 1;i++)        
        	if(nums[i] < nums[i + 1])
        	{
        		flag[i] = 1;
        		pos = i;
        	}
        if(pos == -1)
        {
        	int i = 0,j = n - 1;
        	while(i < j)
        	{
        		temp = nums[j];
        		nums[j] = nums[i];
        		nums[i] = temp;
        		i++;
        		j--;
        	}
        }
        else
        {
        	int i = pos + 2;
        	int j = pos + 1;
        	temp = nums[j];
        	while(i < n)
        	{
        		if(nums[i] > nums[pos] && nums[i] < temp)
        		{
        			j = i;
        			temp = nums[i];
        		}
        		i++;
        	}
        	nums[j] = nums[pos];
        	nums[pos] = temp;
        	sort(nums, pos + 1, n - 1);
        }
    }
};