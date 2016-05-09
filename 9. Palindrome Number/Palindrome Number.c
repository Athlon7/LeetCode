bool isPalindrome(int x)
{
    int temp, left, right; 
    short i, j;
    short cnt = 0;
    bool odd;
    
    if(x < 0)
    	return false;
    // Digit count    
    temp = x;
    while(temp != 0)
    {
    	temp /= 10;
    	cnt++;
    }

    for(i = 0;i < cnt;i++)
    {
    	left = x;
    	for(j = 0;j < cnt - 1 - i;j++)
    		left /= 10;
    	left = left % 10;

    	right = x;
    	for(j = 0;j < i;j++)
    		right /= 10;
    	right = right % 10;

    	if(left != right)
    		return false;
    }    
    return true;
}