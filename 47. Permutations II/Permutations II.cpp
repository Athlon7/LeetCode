class Solution
{
public:
    void spread(vector<int> &nums, vector<vector<int> > &ans)
    {
        static vector<int> temp;
        static vector<bool> flags(nums.size(), true);
        vector<int> used;

        for(int i = 0;i < nums.size();++i)
        {
            if(flags[i] && (find(used.begin(), used.end(), nums[i]) == used.end()))
            {
                flags[i] = false;
                temp.push_back(nums[i]);
                if(i + 1 < nums.size() && nums[i + 1] == nums[i])
                    used.push_back(nums[i]);
                if(temp.size() == nums.size())
                    ans.push_back(temp);
                spread(nums, ans);
                temp.pop_back();
                flags[i] = true;
            }
        }
        
    }

    vector<vector<int> > permuteUnique(vector<int>& nums)
    {
        vector<vector<int> > ans;

        sort(nums.begin(), nums.end());
        spread(nums, ans);
        return ans;
    }
};