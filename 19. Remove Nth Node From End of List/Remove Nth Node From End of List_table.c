/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    int i, max;
    struct ListNode *ptr, *ptr1;
    int table[1000] = {0};      //用来存地址，假设最多1000节点

    ptr = head;
    i = 0;
    table[i++] = ptr;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
        table[i++] = ptr;
    }
    max = i;
    // 只有一个节点
    if(max == 1)
        return NULL;
    // 去掉头结点
    if(n == max)
    {
        head = head->next;
        return head;
    }
    // 去掉尾节点
    if(n == 1)
    {
        ptr = table[max - n - 1];
        ptr->next = NULL;
        return head;
    }
    // 正常情况
    ptr = table[max - n - 1];
    ptr1 = table[max - n + 1];
    ptr->next = ptr1;
    return head;
}