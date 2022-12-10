/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        long long total = 0;
    long long ans = 0;
    int mod = 1e9 + 7;
    long long totalSum(TreeNode *root)
    {
        if (!root) return 0;
        return root->val + totalSum(root->left) + totalSum(root->right);
    }
    long long helper(TreeNode *root)
    {
        if (!root) return 0;
        long long p = helper(root->left);
        long long q = helper(root->right);
        ans = max(ans, (total - p) *p);
        ans = max(ans, (total - q) *q);
       	// if(ans >= mod) ans = ans % mod;
        return p + q + root->val;
    }
    int maxProduct(TreeNode *root)
    {
        total = totalSum(root);
        cout<<total<<endl;
        helper(root);
        // cout<<ans<<endl;
        ans = ans % mod;
        return ans;
    }
};