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
    int msum = INT_MIN;
    int helper(TreeNode* root){
        if(!root) return 0;
        int p = helper(root->left);
        int q = helper(root->right);
        msum = max(msum,p + q + root->val);
        int x = max({p,q,0}) + root->val;
        msum = max(x,msum);
        return x;
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        helper(root);
        return msum;
    }
};