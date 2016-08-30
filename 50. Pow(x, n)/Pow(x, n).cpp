class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = x;
        if(n == 0)
            return 1;        
        if(n == 1 || x == 1.0)
            return x;
        else if(n > 0)
        {
            int half = n / 2;
            if(n % 2 == 0)
            {               
                ans = myPow(x, half);
                ans *= ans; 
            }
            else
            {
                ans = myPow(x, half);
                ans *= ans * x;
            }
                    
        }
        else
        {                   
            if(n == -2147483648)
            {
                n = 2147483647;
                ans = 1 / (myPow(x, n) * x);
            }
            else
                ans = 1 / myPow(x, -n);
        }
        return ans;
    }
};