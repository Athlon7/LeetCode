class Solution
{
public:
    int findComb(vector<int>& candidates, vector<vector<int> >& ans, int target, int num)
    {
        int temp = target;
        static int cnt = 0;
        static vector<int> stack;
        bool flag = false;

        for(int i = num;i < candidates.size();++i)
        {            
            if(flag && i > 0 && candidates[i] == candidates[i - 1])
                continue;
            if(candidates[i] <= target)
            {
                temp = target - candidates[i];
                stack.push_back(candidates[i]); //push
                if(temp == 0)   //found target
                {
                    ans.push_back(stack);
                    stack.pop_back();
                    flag = true;
                    continue;
                }
                findComb(candidates, ans, temp, i + 1);
                stack.pop_back();
            }
            flag = true;
        }
        return 0;
    }

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end(), greater<int>());        
        vector<vector<int> > ans;
        findComb(candidates, ans, target, 0);
        return ans;
    }
};