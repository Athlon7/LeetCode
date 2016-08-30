class Solution
{
public:
    void spread(vector<int> &nums, vector<vector<int> > &ans)
    {
        static vector<int> temp;
        static vector<bool> flags(nums.size(), true);
        for(int i = 0;i < nums.size();++i)
        {
            if(flags[i])
            {
                flags[i] = false;
                temp.push_back(nums[i]);
                if(temp.size() == nums.size())
                    ans.push_back(temp);
                spread(nums, ans);
                temp.pop_back();
                flags[i] = true;
            }           
        }
        
    }

    vector<vector<int> > permute(vector<int>& nums)
    {
        vector<vector<int> > ans;

        spread(nums, ans);
        return ans;
    }
};