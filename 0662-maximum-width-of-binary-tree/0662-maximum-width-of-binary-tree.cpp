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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int mlen = 1;
        while(!q.empty()){
            int n = q.size();
            auto p = q.front();
            long long mini = p.second;
            int start,end;
            for(int i=0;i<n;i++){
                auto p = q.front();
                long long val = p.second - mini;
                auto node = p.first;
                q.pop();
                if(node->left) q.push({node->left,val*2 + 1});
                if(node->right) q.push({node->right,val*2 + 2});
                if(i == 0) start = val;
                if(i == n-1) end = val;
            }
            // cout<<start<<" "<<end<<endl;
            mlen = max(mlen,end - start + 1);
        }
        return mlen;
    }
};