#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int binSearch(vector<int> &nums, int target, int left, int right)
    {
        int i = left, j = right, mid;

        while(i <= j)
        {
            mid = (i + j) / 2;
            if(nums[mid] == target)
                return mid;
            else if(target > nums[mid])
                i = mid + 1;
            else if(target < nums[mid])
                j = mid - 1;
        }
        return -1;
    }

    // 先折半然后再附近遍历寻找
    // vector<int> searchRange(vector<int>& nums, int target)
    // {
    //     int length = nums.size();
    //     int ans, i;
    //     vector<int> pos(2, -1);

    //     if((ans = binSearch(nums, target, 0, length - 1)) == -1)
    //      return pos;
    //     else
    //     {
    //      for(i = ans;i >= 0;--i)
    //      {
    //          if(nums[i] != target)
    //              break;
    //      }
    //      pos[0] = i + 1;
    //      for(i = ans;i < length;++i)
    //          if(nums[i] != target)
    //              break;
    //      pos[1] = i - 1;
    //     }
    //     return pos;
    // }
    // 
    
    // 始终折半
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int length = nums.size();
        int ans, i;
        vector<int> pos(2, -1);

        if((ans = binSearch(nums, target, 0, length - 1)) == -1)
            return pos;
        else
        {
            int front_right = ans - 1, rare_left = ans + 1;
            pos[0] = ans;
            pos[1] = ans;
            int front = 1;
            while(front > 0)
            {
                front = binSearch(nums, target, 0, front_right);
                if(front != -1)
                {
                    pos[0] = front;                    
                    front_right = front - 1;
                }
            }
            int rare = 1;
            while(rare < length && rare != -1)
            {
                rare = binSearch(nums, target, rare_left, length -1);
                if(rare != -1)
                {
                    pos[1] = rare;
                    rare_left = rare + 1;                    
                }
            }
        }
        return pos;
    }
};

int main()
{
    Solution a;
    int ans;
    vector<int> input(10);
    vector<int> output;
    for(int i = 0;i < 10;++i)
    {
        input[i] = i / 2;
    }
    for(vector<int>::iterator i = input.begin();i != input.end();++i)
        cout << *i << " ";
    cout << endl;

    output = a.searchRange(input, 2);
    
    for(vector<int>::iterator i = output.begin();i != output.end();++i)
        cout << *i << " ";
}