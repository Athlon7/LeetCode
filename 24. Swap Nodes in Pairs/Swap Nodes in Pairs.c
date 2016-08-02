/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head)
{
    if(head == NULL)
    	return NULL;    
    
    struct ListNode *p;
    int table[2000] = {0};
    int i = 0, j = 0, temp;

    p = head;
    while(p != NULL)
    {
    	table[i++] = p;
    	p = p->next;
    }

    if(i >= 2)
    {
    	while(j < i - 1)
    	{
    		temp = table[j];
    		table[j] = table[j + 1];
    		table[j + 1] = temp;
    		j = j + 2;
    	}
    	head = table[0];
    	p = head;    	
    	for(j = 0;j < i - 1;j++)
    	{
    		p->next = table[j + 1];
    		p = p->next;
    	}
    	p->next = NULL;
    	return head;
    }

    return head;
}