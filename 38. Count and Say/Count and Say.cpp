class Solution
{
public:
    string countAndSay(int n)
    {
        string ans;
        for(int i = 0;i < n;++i)
        {
            if(i == 0)
                ans = "1";
            else
            {
                int j = 0, cnt = 0, temp_num;
                string temp_ans;
                char pre = ans[0];
                stringstream stream;

                while(ans[j] != '\0')
                {
                    if(ans[j] == pre)
                        ++cnt;
                    else
                    {
                        stream << cnt << pre;
                        pre = ans[j];
                        cnt = 1;
                    }
                    ++j;
                }
                stream << cnt << pre;
                stream >> ans;
            }
        }
        return ans;
    }
};