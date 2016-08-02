/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    if(head == NULL)
    	return NULL; 
    if(k == 1)
    	return head;

    struct ListNode *p;
    int table[5000] = {0};
    int i = 0, j = 0, l, temp, k1;

    p = head;
    while(p != NULL)
    {
    	table[i++] = (int)p;
    	p = p->next;
    }
    if(i < k)
    	return head;

    k1 = (int)(k / 2);

    while(j < i - k + 1)
    {
    	for(l = 0;l < k1;l++)
    	{
    		temp = table[j + l];
    		table[j + l] = table[j + k - 1 - l];
    		table[j + k - 1 - l] = temp;
    	}
    	j = j + k;
    }

    head = (struct ListNode*)table[0];
    p = head;    	
    for(j = 0;j < i - 1;j++)
    {
    	p->next = (struct ListNode*)table[j + 1];
    	p = p->next;
    }
    p->next = NULL;    

    return head;
}