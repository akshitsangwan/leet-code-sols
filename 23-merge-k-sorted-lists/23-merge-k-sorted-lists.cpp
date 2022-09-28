/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    class cmp
    {
        public:
        bool operator()(ListNode* a, ListNode* b) 
        {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> minheap;
        
        int k=lists.size();
        if(k==0)
            return NULL;
        
        
        ListNode* head=NULL;
        ListNode* tail=NULL;
        for(int i=0;i<k;i++)
        {
            if(lists[i]!=NULL)
                minheap.push(lists[i]);
        }
        
        while(!minheap.empty())
        {
            // when LL is empty
            if(head==NULL)
            {
                head=tail=minheap.top();
                minheap.pop();
            }
            // insert node to LL
            else
            {
                tail->next=minheap.top();
                minheap.pop();
                tail=tail->next;
            }
            if(tail->next!=NULL)
                    minheap.push(tail->next);
        }
        return head;
    }
};