/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *p1, *p2, *ptr1, *ptr2;
    struct ListNode d1 = {0, l1}, d2 = {0, l2};

    // 有空链的情况
    if(l1 == NULL)
    	if(l2 == NULL)
    		return NULL;
    	else
    		return l2;
    else if(l2 == NULL)
    	return l1;

    // 从题目给出答案来看应该是升序的
    // 头结点处理起来比较麻烦，用假节点来处理
    p1 = l1;
    p2 = l2;
    l1 = &d1;
    l2 = &d2;
    ptr1 = l1;
    ptr2 = l2;

    while(ptr2->next != NULL)
    {
    	if(ptr1->next == NULL)
    	{
    		ptr2->next = p2->next;    		
    		p2->next = p1;
    		ptr1->next = p2;
    		p1 = p2;
    		p2 = ptr2->next;
    	}
    	else if(p2->val < p1->val)
    	{
    		ptr2->next = p2->next;    		
    		p2->next = p1;
    		ptr1->next = p2;
    		p1 = p2;
    		p2 = ptr2->next;
    	}
    	else
    	{
    		ptr1 = p1;
    		p1 = p1->next;    		
    	}
    }
    l1 = l1->next;
    return l1;
}