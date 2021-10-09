// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head==NULL)
            return head;
        
        vector<ListNode *> v;
        int count=0;
        ListNode *p=head;
        
        while(p!=NULL)
        {
            v.push_back(p);
            count++;
            p=p->next;
        }
        
        if(count-n-1==-1)
        {
            ListNode *temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        
        v[count-n-1]->next=v[count-n]->next;
            
        return head;
    }
};