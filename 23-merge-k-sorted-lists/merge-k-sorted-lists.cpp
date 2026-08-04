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
    ListNode* mergeLinkList(ListNode* l1,ListNode* l2){
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        if(h1 == nullptr) return h2;
        if(h2 == nullptr) return h1;

        if(h1->val <= h2->val){
            h1->next = mergeLinkList(h1->next,h2);
            return  h1;
        }
        else{
            h2->next = mergeLinkList(h1,h2->next);
            return h2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* ans = nullptr;
    for(auto it:lists){
        ans = mergeLinkList(ans,it);
    }
    return ans;
        
    }
};