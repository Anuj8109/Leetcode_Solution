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
    void flatten(TreeNode* root) {
        if(!root) return ;
        if(root->left){
            flatten(root->left);
            auto p = root->left;
            root->left = NULL;
            auto temp = p;
            while(temp->right){
                temp = temp->right;
            }
            auto q = root->right;
            root->right = p;
            temp->right = q;
        }

        flatten(root->right);
    }
};