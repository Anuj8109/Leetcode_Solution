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
    public int maxLevelSum(TreeNode root) {
        Queue<TreeNode> list = new LinkedList<TreeNode>();
        list.add(root);
        int result = Integer.MIN_VALUE;
        int level = 0;
        int height = 0;
        while(!list.isEmpty()){
            int size = list.size();
            int curr = 0;
            height++;
            // Queue<TreeNode> next = new List
            for(int index=0;index<size;index++){
                TreeNode temp = list.poll();
                curr += temp.val;
                if(temp.left != null) list.add(temp.left);
                if(temp.right != null) list.add(temp.right);
            }
            if(result < curr){
                // System.out.println(curr + " " + result + " " + height);
                result = curr;
                level = height;
            }
            result = Math.max(result, curr);
        }
        return level;
    }
}