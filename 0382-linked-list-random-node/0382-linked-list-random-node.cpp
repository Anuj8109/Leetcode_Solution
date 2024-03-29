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
    vector<int> v;
    int len = 0;
    ListNode* h;
    Solution(ListNode* head) {
        ListNode* temp = head;
        h = head;
        while(temp){
            temp = temp->next;
            len ++;
        }
    }
    int getRandom() {
        int p = rand() % len;
        ListNode* temp = h;
        while(p > 0){
            temp = temp->next;
            p--;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */