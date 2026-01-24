class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int len = nums.length;
        int sum = 0; 
        for(int index=0;index<len/2;index++){
            int currSum = nums[index] + nums[len - 1 - index];
            // System.out.println(currSum + " " + sum);
            sum = Math.max(sum, currSum);
        }
        return sum;
    }
}