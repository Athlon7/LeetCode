class Solution
{
public:
    int findComb(vector<int>& candidates, vector<vector<int> >& ans, int target, int num)
    {
        int temp = target;
        static int cnt = 0;
        static vector<int> stack;

        for(int i = num;i < candidates.size();++i)
        {
            if(candidates[i] <= target)
            {
                temp = target - candidates[i];
                stack.push_back(candidates[i]);

                if(temp == 0)   //found target
                {
                    ans.push_back(stack);                    
                    stack.pop_back();
                    continue;
                }
                findComb(candidates, ans, temp, i);
                stack.pop_back();                
            }
        }
        return 0;
    }

    vector<vector<int> > combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end(), greater<int>());
        vector<vector<int> > ans;
        findComb(candidates, ans, target, 0);
        return ans;
    }
};
