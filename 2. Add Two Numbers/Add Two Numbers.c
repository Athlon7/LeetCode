/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int temp;
    int carry;
    struct ListNode *ptr1, *ptr2, *ptr3;

    //first digit
    ptr1 = l1;
    ptr2 = l2;
    temp = ptr1->val + ptr2->val;
    if (temp < 10)
    {
    	carry = 0;
    	ptr1->val = temp;
    	ptr2->val = temp;	
    }
    else
    {
    	temp = temp - 10;
    	carry = 1;
    	ptr1->val = temp;
    	ptr2->val = temp;
    }

    //loop
    while ((ptr1->next != NULL) || (ptr2->next != NULL))
    {
    	//if one is longer than the other fill 0
    	if (ptr1->next == NULL)
    	{
    		ptr3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    		ptr3->val = 0;
    		ptr3->next = NULL;
    		ptr1->next = ptr3;
    	}
    	else if (ptr2->next == NULL)
    	{
    		ptr3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    		ptr3->val = 0;
    		ptr3->next = NULL;
    		ptr2->next = ptr3;
    	}

    	ptr1 = ptr1->next;
    	ptr2 = ptr2->next;

    	temp = ptr1->val + ptr2->val + carry;
    	if (temp < 10)
    	{
    		carry = 0;
    		ptr1->val = temp;
    		ptr2->val = temp;	
    	}
    	else
    	{
    		temp = temp - 10;
    		carry = 1;
    		ptr1->val = temp;
    		ptr2->val = temp;
    	}
    }

    //if carry remains 1
    if (carry == 1)
    {
    	ptr2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    	ptr2->val = 1;
    	ptr2->next = NULL;
    	ptr1->next = ptr2;
    	return l1;
    }

    return l1;
}