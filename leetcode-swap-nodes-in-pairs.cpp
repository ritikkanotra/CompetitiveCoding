// https://leetcode.com/problems/swap-nodes-in-pairs/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(head==NULL)
            return head;
        
        ListNode *p=head,*prev=NULL;
        
        while(p && p->next)
        {
            if(prev==NULL)
            {
                ListNode *temp=head;
                head=head->next;
                temp->next=head->next;
                head->next=temp;
                prev=head->next;
                p=head->next->next;
            }
            else
            {
                prev->next=p->next;
                ListNode *temp=p->next;
                p->next=temp->next;
                temp->next=p;
                prev=p;
                p=p->next;
            }
        }
        
        return head;
    }
};