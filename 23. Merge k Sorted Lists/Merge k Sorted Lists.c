/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if(listsSize == 0)
    	return NULL;
    if(listsSize == 1)
    	return lists[0];

    struct ListNode *head_m, *head_b, *p_m, *p_b, *ptr_m, *ptr_b;
    int max = 0, i, cnt, master;
    struct ListNode d_m = {0, NULL}, d_b = {0, NULL};
    int *flags;

    flags = (int *)malloc(sizeof(int) * listsSize);
    memset(flags, 0, sizeof(int) * listsSize);

    head_m = NULL;
    // 选出一个最长链，其他链向里插入
    for(i = 0;i < listsSize;i++)
    {
    	if(lists[i] == NULL)
    	{
    		flags[i] = 1;
    		continue;
    	}
    	head_m = lists[i];
    	master = i;

    	// cnt = 0;
    	// p_b = lists[i];
    	// while(p_b != NULL)
    	// {
    	// 	p_b = p_b->next;
    	// 	cnt++;
    	// }
    	// if(cnt > max)
    	// {
    	// 	max = cnt;
    	// 	head_m = lists[i];
    	// 	master = i;
    	// }
    }    
    if(head_m == NULL)
    	return NULL;
    flags[master] = 1;
    
    // 给主链添加辅助节点
    d_m.next = head_m;
    head_m = &d_m;
    ptr_m = head_m;
    p_m = head_m->next;

    // 主循环
    for(i = 0;i < listsSize;i++)
    {
    	if(flags[i] == 1)
    		continue;

    	// 给支链添加辅助节点
    	d_b.next = lists[i];
    	head_b = &d_b;
    	ptr_b = head_b;
    	p_b = head_b->next;

    	while(p_b != NULL)
    	{
    		// 主链已经到末尾的情况
    		if(p_m == NULL)
    		{
    			ptr_m->next = p_b;
    			break;
    		}
    		// 支链当前节点比主链当前节点小，插在主链前
    		if(p_b->val <= p_m->val)
    		{
    			ptr_b->next = p_b->next;
    			p_b->next = p_m;
    			ptr_m->next = p_b;
    			p_b = ptr_b->next;
    			ptr_m = ptr_m->next;
    		}
    		// 支链比主链大，主链节点后移
    		else
    		{
    			p_m = p_m->next;
    			ptr_m = ptr_m->next;
    		}
    	}

    	// 一条支链插入完毕，主链指针复位
    	ptr_m = head_m;
    	p_m = head_m->next;
    }

    return head_m->next;
}