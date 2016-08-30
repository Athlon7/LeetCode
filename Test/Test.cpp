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
    vector<int> spiralOrder(vector<vector<int> >& matrix)
    {
        vector<int> ans;
        if(matrix.size() == 0)
            return ans;
        int num = matrix.size() * matrix[0].size();
        int up = 0, down = matrix.size() - 1, left = 0;
        int right = matrix[0].size() - 1;

        while(ans.size() != num)
        {
            for(int i = left;i <= right;++i)
                ans.push_back(matrix[up][i]);
            if(ans.size() == num)
                break;
            ++up;
            for(int i = up;i <= down;++i)
                ans.push_back(matrix[i][right]);
            if(ans.size() == num)
                break;
            --right;
            for(int i = right;i >= left;--i)
                ans.push_back(matrix[down][i]);
            if(ans.size() == num)
                break;
            --down;
            for(int i = down;i >= up;--i)
                ans.push_back(matrix[i][left]);
            if(ans.size() == num)
                break;
            ++left;
        }
        return ans;
    }
};


int main()
{
    Solution a;

    vector<int> output;
    // vector<vector<string> > output;
    // int output;
    // string output;
    // bool output;
    // double output;

    int array[] = {1,2,3,4,5,6,7,8,9};
    //vector<int> input(array, array + 14);

    string input1= "", input2 = "b";
    vector<vector<int> > input(1);
    // input.push_back(input1);
    // input.push_back(input2);
    // cout << input[0] << " " << input[1];
    input[0].assign(array + 1, array + 3);
    // input[1].assign(array + 3, array + 6);
    // input[2].assign(array + 6, array + 9);

    // output = a.add(input1, input2);
    output = a.spiralOrder(input);

    for(int i = 0;i < output.size();++i)
    {
        cout << output[i] << " ";
    }
}