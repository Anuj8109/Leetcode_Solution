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
    pair<int,int> helper(TreeNode* root,int &ans){
        if(!root){
            return {0,0};
        }
        auto p = helper(root->left,ans);
        auto q = helper(root->right,ans);
        // int p  = helper(root->left,ans,1);
        // int q  = helper(root->right,ans,0);
        ans = max({p.first,p.second,q.first,q.second,ans});
        // cout<<p.first<<" "<<p.second<<" "<<q.first<<" "<<q.second<<endl;
        // cout<<p<<" "<<q<<" "<<root->val<<endl;
        return {q.second + 1,p.first + 1};
        // return dir ? q + 1 : p + 1;
    }
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        auto p = helper(root,ans);
        cout<<p.first<<" "<<p.second<<endl;
        ans = max({ans,p.first,p.second});
        return ans - 1;
    }
};