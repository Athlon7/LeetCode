class Solution
{
public:
    bool isMatch(string s, string p, int i = 0, int j = 0)
    {
        int ls = s.size(), lp = p.size();

        int char_cnt = 0;
        char next_char;
        bool flag;
        for(;i < lp;++i)
        {
            // '?' case
            if(p[i] == '?')
            {
                ++j;
            }
            // '*' case
            else if(p[i] == '*')
            {
                char_cnt = 0;
                while(p[i] == '*' || p[i] == '?')
                {
                    if(p[i] == '?')
                        ++char_cnt;
                    ++i;
                }
                if(i == lp)
                {
                    if(ls - j >= char_cnt)
                        return true;
                    else
                        return false;
                }
                else
                {
                    while(1)
                    {
                       while(s[j] != p[i] && j < ls)
                           ++j;
                       if(j >= ls)
                           return false;

                       if(isMatch(s, p, i, j))
                           return true;
                       else ++j; 
                    }                                        
                }
            }
            // character case
            else
            {
                if(s[j] != p[i])
                    return false;
                else
                    ++j;
            }

            if(j == ls && i != lp - 1)
            {
                do
                    ++i;
                while(p[i] == '*');
                if(i == lp)
                    return true;
                return false;
            }
        }
        if(j != ls)
            return false;
        return true;
    }
};