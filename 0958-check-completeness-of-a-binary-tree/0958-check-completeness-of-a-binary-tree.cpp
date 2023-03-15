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
    bool isCompleteTree(TreeNode* root) {
        bool comp = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            if(!comp  && (p->left || p->right)) return 0;
            if(p->left) q.push(p->left);
            else{
                comp = 0;  
                if(p->right) return 0;
            }
            if(p->right) q.push(p->right);
            else comp = 0;
            
            
            
        }
        return 1;
    }
};