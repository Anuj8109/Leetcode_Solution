/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private static int sum = 0;
    private static long result = 0l;
    private static final long mod = (long)(1e9 + 7);
    public void sum(TreeNode node){
        if(node == null) return ;

        sum += node.val;
        sum(node.left);
        sum(node.right);
    }

    public int dfs(TreeNode root){
        if(root == null) return 0;

        int leftChild = dfs(root.left);
        int rightChild = dfs(root.right);
        //left node brake 
        result = Math.max(result, (long)leftChild*(sum-leftChild));
        //right node brake 
        result = Math.max(result, (long)rightChild*(sum-rightChild));
        // result = Math.max(result, (long)child*(sum - child));

        return root.val + leftChild + rightChild;
    }
    public int maxProduct(TreeNode root) {
        sum = 0;
        result = 0l;
        sum(root);
        dfs(root);
        return (int)(result % mod);
    }
}