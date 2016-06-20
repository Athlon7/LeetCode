/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    int i;
    struct ListNode *ptr, *ptr1;

    ptr = head;
    ptr1 = head;        
    for(i = 0;i < n;i++)
    {
    	if(ptr->next != NULL)
    		ptr = ptr->next;
    	// 去掉头结点的情况
    	else
    	{
    		if(n == 1)
    			return NULL;
    		head = head->next;
    		return head;
    	}
    }   
    	
    while(ptr->next != NULL)
    {
    	ptr = ptr->next;
    	ptr1 = ptr1->next;
    }
    
    // 去掉尾节点
    if(n == 1)
    {
    	ptr1->next = NULL;
    	return head;
    }   

    // 其他情况
    ptr = ptr1->next;
    ptr = ptr->next;
    ptr1->next = ptr;

    return head;
}