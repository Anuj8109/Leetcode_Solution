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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        queue<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            auto p = s.front();
            // cout<<p->val<<endl;
            s.pop();
            if(p->val >= low && p->val <=high) ans += p->val;
            if(p->left && p->val > low) s.push(p->left);
            if(p->right && p->val < high) s.push(p->right);
        }
        return ans;
    }
};