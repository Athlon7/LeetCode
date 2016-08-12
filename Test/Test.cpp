#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <algorithm>

using namespace std;

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
                cout << "stack push:";
                for(vector<int>::iterator j = stack.begin();j != stack.end();++j)
                        cout << *j << " ";
                cout << endl;

                if(temp == 0)   //found target
                {
                    ans.push_back(stack);
                    cout << "out:"; 
                    for(vector<int>::iterator j = stack.begin();j != stack.end();++j)
                        cout << *j << " ";
                    cout << endl;
                    stack.pop_back();
                    flag = true;
                    continue;
                }
                findComb(candidates, ans, temp, i + 1);
                stack.pop_back();

                cout << "stack_pop:";
                for(vector<int>::iterator j = stack.begin();j != stack.end();++j)
                        cout << *j << " ";
                cout << endl;
            }
            flag = true;
        }
        return 0;
    }

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end(), greater<int>());

        for(vector<int>::iterator i = candidates.begin();i != candidates.end();++i)
            cout << *i << " ";
        vector<vector<int> > ans;

        findComb(candidates, ans, target, 0);
        return ans;
    }
};

int main()
{
    Solution a;

    vector<vector<int> > output;  

    vector<int> input(7);
    input[0] = 10; 
    input[1] = 1;
    input[2] = 2;
    input[3] = 7;
    input[4] = 6;
    input[5] = 1;
    input[6] = 5;

    output = a.combinationSum2(input, 8);
}