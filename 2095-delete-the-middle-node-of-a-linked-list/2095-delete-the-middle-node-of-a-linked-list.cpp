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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head -> next) return NULL;
        auto slow = head;
        auto fast = head->next->next;
        // auto prev = head;
        while(fast && fast->next){
            // cout<<slow->val<<" "<<fast->val<<endl;
            // prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        slow -> next = slow -> next -> next;
        // cout<<fast->val<<endl;
        // if(fast == NULL) prev->next = slow->next;
        // else slow -> next = slow -> next -> next;
        return head;
    }
};