#define MAX_INT 2147483647
#define MIN_INT -2147483648
int divide(int dividend, int divisor)
{
    if(divisor == 0)
        return MAX_INT;
    if(dividend == 0)
        return 0;

    if(divisor == 1)
        return dividend;
    if(divisor == -1)
    {
        if(dividend > 0)
            return -dividend;
        else
        {
            dividend = -dividend;
            if(dividend <= 0)
                return MAX_INT;
            return dividend;
        }
    }

    int result = 0, table[3][32] = {0}, temp = 0, i = 0, modi = 1, j;

    if(dividend < 0 && divisor > 0)
    {       
        // 构建一个表
        temp = -divisor;
        while(temp >= dividend)
        {
            table[0][i] = temp;
            table[1][i++] = modi;
            modi += modi;
            temp += temp;
            if(temp >= 0)
                break;
        }
        // 利用表来做除法
        i--;
        while(i >= 0)
        {
            while(dividend <= table[0][i])
            {
                dividend = dividend - table[0][i];
                table[2][i]++;
            }
            i--;
        }
        // 统计表里的结果
        for(i = 0;i < 32;i++)
        {
            for(j = 0;j < table[2][i];i++)
            {
                result -= table[1][i];
            }
        }
    }
    else if(dividend > 0 && divisor < 0)
    {
        // 构建一个表
        temp = divisor;
        dividend = -dividend;
        while(temp >= dividend)
        {
            table[0][i] = temp;
            table[1][i++] = modi;
            modi += modi;
            temp += temp;
            if(temp >= 0)
                break;
        }
        // 利用表来做除法
        i--;
        while(i >= 0)
        {
            while(dividend <= table[0][i])
            {
                dividend = dividend - table[0][i];
                table[2][i]++;
            }
            i--;
        }
        // 统计表里的结果
        for(i = 0;i < 32;i++)
        {
            for(j = 0;j < table[2][i];i++)
            {
                result -= table[1][i];
            }
        }
    }
    else if(dividend < 0 && divisor < 0)
    {       
        // 构建一个表
        temp = divisor;
        while(temp >= dividend)
        {
            table[0][i] = temp;
            table[1][i++] = modi;
            modi += modi;
            temp += temp;
            if(temp >= 0)
                break;
        }
        // 利用表来做除法
        i--;
        while(i >= 0)
        {
            while(dividend <= table[0][i])
            {
                dividend = dividend - table[0][i];
                table[2][i]++;
            }
            i--;
        }
        // 统计表里的结果
        for(i = 0;i < 32;i++)
        {
            for(j = 0;j < table[2][i];i++)
            {
                result += table[1][i];
            }
        }
    }
    else
    {
        // 构建一个表
        temp = -divisor;
        dividend = -dividend;
        while(temp >= dividend)
        {
            table[0][i] = temp;
            table[1][i++] = modi;
            modi += modi;
            temp += temp;
            if(temp >= 0)
                break;
        }
        // 利用表来做除法
        i--;
        while(i >= 0)
        {
            while(dividend <= table[0][i])
            {
                dividend = dividend - table[0][i];
                table[2][i]++;
            }
            i--;
        }
        // 统计表里的结果
        for(i = 0;i < 32;i++)
        {
            for(j = 0;j < table[2][i];i++)
            {
                result += table[1][i];
            }
        }
    }
    return result;
}