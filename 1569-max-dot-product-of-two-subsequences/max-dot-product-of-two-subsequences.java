class Solution {
    Integer[][] dp;
    public int maxProduct(int[] nums1, int[] nums2, int p, int q, boolean isEmpty){
        if(p == nums1.length || q == nums2.length){
            if(isEmpty) return Integer.MIN_VALUE>>1;
            return 0;
        }
        if(dp[p][q] != null) return dp[p][q];
        int result = maxProduct(nums1, nums2, p + 1, q, isEmpty);

        if(nums1[p] == 0){
            return Math.max(0, result);
        }

        for(int index=q;index<nums2.length;index++){
            int curr = nums1[p] * nums2[index]
                    + maxProduct(nums1, nums2, p + 1, index + 1, false);
            result = Math.max(result, curr);
        }
        return dp[p][q] = result;
    }
    public int maxDotProduct(int[] nums1, int[] nums2) {
        dp = new Integer[nums1.length][nums2.length];

        // for(int )
        return maxProduct(nums1, nums2, 0, 0, true);
    }
}