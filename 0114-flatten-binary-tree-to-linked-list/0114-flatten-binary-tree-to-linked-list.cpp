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
            auto temp = root->left;
            while(temp->right){
                temp = temp->right;
            }
            temp->right = root->right;
            // auto q = root->right;
            root->right = root->left;
            root->left = NULL;
            // temp->right = q;
        }

        flatten(root->right);
    }
};