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
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;
        if(lists.empty())return NULL;
        for(auto& x:lists){
            if(x){
                auto y=x;
                while(y){
                    pq.push(y);
                    y=y->next;
                }
            }
        }
        if(pq.size()==0)return NULL;
        auto hd=pq.top();
        while(!pq.empty()){
            auto x=pq.top();pq.pop();
            if(pq.empty())x->next=NULL;
            else{
                x->next=pq.top();
            }
        }
        return hd;
    }
};