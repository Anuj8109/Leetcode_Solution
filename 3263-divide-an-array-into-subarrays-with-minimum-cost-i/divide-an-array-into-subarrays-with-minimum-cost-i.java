class Solution {
    public int minimumCost(int[] nums) {
        int len = nums.length;
        int[] mini = new int[len];
        mini[len - 1] = nums[len - 1];

        for(int index=len-2;index>=0;index--){
            mini[index] = Math.min(mini[index + 1], nums[index]);
        }

        int result = Integer.MAX_VALUE;
        for(int index=1;index<len - 1;index++){
            int curr = nums[0] + nums[index] + mini[index+1];
            result = Math.min(result, curr);
        }
        return result;

    }
}