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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        auto slow = head;
        auto fast = head;
        ListNode* prev = NULL;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        auto p = new TreeNode(slow->val);
        if(prev){
            prev->next = NULL;
            p->left = sortedListToBST(head);
        }
        p->right = sortedListToBST(slow->next);
        return p;
    }
};