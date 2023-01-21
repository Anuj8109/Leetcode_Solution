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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto p = head;
        ListNode* q = head;
        while(n > 1){
            q = p;
            p = p->next;
            n--;
        }
        // cout<<p->val<<endl;
        if(p == NULL){
            q->next = NULL;
            return head;
        }
        q = head;
        p = p->next;
        if(!p ) return head->next;
        while(p->next){
            p = p->next;
            q = q->next;
        }
        // cout<<q->val<<endl;
        // if(q == head) return head->next;
        q->next = q->next->next;
        return head;
    }
};