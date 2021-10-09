// https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *head;
        
        if(l1==NULL)
            return l2;
        else
            if(l2==NULL)
                return l1;
        else
            if(l1==NULL && l2==NULL)
                return NULL;
        else
        {
            if(l1->val<=l2->val)
            {
                head=l1;
                l1=l1->next;
            }
            else
                if(l2->val<l1->val)
                {
                    head=l2;
                    l2=l2->next;
                }
        }
        
        ListNode *p=head;
        while(l1 && l2)
        {
            if(l1->val<l2->val)
            {
                p->next=l1;
                l1=l1->next;
            }
            else
                if(l2->val<l1->val)
                {
                    p->next=l2;
                    l2=l2->next;
                }
            else
            {
                p->next=l1;
                p=p->next;
                l1=l1->next;
                p->next=l2;
                l2=l2->next;
            }
            
            p=p->next;
        }
        
        while(l1!=NULL)
        {
            p->next=l1;
            p=p->next;
            l1=l1->next;
        }
        
        while(l2!=NULL)
        {
            p->next=l2;
            p=p->next;
            l2=l2->next;
        }
        
        return head;
    }
};