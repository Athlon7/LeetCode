/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// ¿ìËÙÅÅÐò
void sort(int* nums, int left, int right)
{
	if(left >= right)
		return;

	int temp;
	int i = left;
	int j = right;

	temp = nums[left];
	while(i < j)
	{
		while(i < j && nums[j] >= temp)
			j--;
		nums[i] = nums[j];
		while(i < j && nums[i] <= temp)
			i++;
		nums[j] = nums[i];		
	}
	nums[i] = temp;

	sort(nums, left, i - 1);
	sort(nums, i + 1, right); 
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if(listsSize == 0)
    	return NULL;
    if(listsSize == 1)
    	return lists[0];

    int nums[2000] = {0};
	struct ListNode *head, *p, *ptr;
	int i,j = 0;

	ptr = NULL;
	for(i = 0;i < listsSize;i++)
	{
		if(lists[i] == NULL)		
			continue;		
		p = lists[i];
		ptr = lists[i];
		while(p != NULL)
		{
			nums[j++] = p->val;
			p = p->next;			
		}		
	}
	if(ptr == NULL)
		return NULL;

	sort(nums, 0, j - 1);

	p = (struct ListNode*)malloc(sizeof(struct ListNode));
	p->val = nums[0];
	head = p;
	ptr = p;

	for(i = 1;i < j;i++)
	{
		p = (struct ListNode*)malloc(sizeof(struct ListNode));
		p->val = nums[i];
		ptr->next = p;
		ptr = p;
	}

	return head;
}