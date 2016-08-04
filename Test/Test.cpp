#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int isValid(string s, int *pos, int *reverse)
    {
    	size_t length = s.size();
        int i = *pos, stack = 0, temp = 0, max = 0;        

        while(i < length)
        {
        	if(s[i] == '(')
        		stack++;
        	else
        		stack--;
        	temp++;
        	if(stack == 0 && temp > max)
        		max = temp;
        	if(stack < 0)
            {
        		*pos = i;
                break;
            }
            i++;
        }

        if(i == length && stack > 5)
            *reverse = stack;
        return max;
    }

    int isValid_rev(string s, int *pos)
    {
        size_t length = s.size();
        int i = *pos, stack = 0, temp = 0, max = 0;        

        while(i >= 0)
        {
            if(s[i] == ')')
                stack++;
            else
                stack--;
            temp++;
            if(stack == 0 && temp > max)
                max = temp;
            if(stack < 0)
            {
                *pos = i;
                break;
            }
            i--;
        }
        return max;
    }

    int longestValidParentheses(string s)
    {
        if(s.size() <= 1)
        	return 0;

        size_t length = s.size();        
        int max = 0, temp, reverse = 0;

        for(int i = 0;i < length - max;i++)
        {
        	if(s[i] == '(')
            {
        		temp = isValid(s, &i, &reverse);
                if(temp > max)
                    max = temp;
                if(reverse)
                    break;
            }            
        }
        if(reverse)
        {
            for(int i = length - 1; i >= 0;i--)
            {
                if(s[i] == ')')
                {
                    temp = isValid_rev(s, &i);
                    if(temp > max)
                        max = temp;
                }
            }
        }
        return max;
    }
};

int main()
{
    Solution a;
    int ans;
    ans = a.longestValidParentheses(")))(()((((((((");
}