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
   bool helper(TreeNode* root,long mini,long maxi){
        if(!root) return 1;
        if(root->val > mini && root->val < maxi){
            return helper(root->left,mini,root->val) && helper(root->right,root->val,maxi);
        }
        return 0;
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return 1;
        return helper(root->left,LONG_MIN,root->val) && helper(root->right,root->val,LONG_MAX);
    }
};