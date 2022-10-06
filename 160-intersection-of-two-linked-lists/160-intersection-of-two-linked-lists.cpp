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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ans=NULL;
        unordered_map<ListNode*,bool> vis;
        
        while(headA!=NULL)
        {
            vis[headA]=true;
            headA=headA->next;
        }
        
        while(headB!=NULL)
        {
            if(vis[headB]==true)
            {
                ans=headB;
                break;
            }
            headB=headB->next;
        }
        return ans;
    }
};