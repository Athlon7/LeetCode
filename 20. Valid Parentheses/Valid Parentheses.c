bool isValid(char* s)
{
    char *stack, *top;
    int i = 0, length;

    // ��ʼ��һ��ջ
    length = strlen(s);
    stack = (char*)malloc(sizeof(char) * length);
    memset(stack, 0, sizeof(char) * length);
    top = stack;

    while(s[i] != '\0')
    {
    	switch(s[i])
    	{
    		case ')': 
    			if(top == stack)
    				return false;
    			else
    			{
    				top--;
    				if(*top != '(')
    					return false;
    			}
    			break;
    		case ']':
    			if(top == stack)
    				return false;
    			else
    			{
    				top--;
    				if(*top != '[')
    					return false;
    			}
    			break;
    		case '}':
    			if(top == stack)
    				return false;
    			else
    			{
    				top--;
    				if(*top != '{')
    					return false;
    			}
    			break;
    		default:
    			*top = s[i];
    			top++;
    			break;
    	}
    	i++;
    }

    if(top != stack)
    	return false;
    return true;
}