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
    void helper(TreeNode* root,long &sum,long curr){
        // if(!root){
        //     sum += curr;
        //     cout<<curr<<endl;
        //     return ;
        // }
        if(!root) return ;
        curr = curr * 10 + root->val;
        if(!root->left && !root->right){
            sum += curr;
            return ;
        }
        helper(root->left,sum,curr);
        helper(root->right,sum,curr);
    }
    int sumNumbers(TreeNode* root) {
        long sum = 0;
        helper(root,sum,0);
        return sum;
    }
};