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

    ListNode* partision(int start,int end,vector<ListNode*>&lists){
        if(start > end) return NULL;
        if(start == end) return lists[start];
        int mid = start+ (end-start)/2;
        ListNode* l1 = partision(start,mid,lists);
        ListNode* l2 = partision(mid+1,end,lists);
        return mergeLinkList(l1,l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        return partision(0,n-1,lists);
    }
};