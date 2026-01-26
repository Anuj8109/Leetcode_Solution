class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int prev = cost[1];
        int prevOfPrev = cost[0];
        for(int index=2;index<cost.length;index++){
            int curr = cost[index] + Math.min(prev, prevOfPrev);
            prevOfPrev = prev;
            prev = curr;
        }
        return Math.min(prev, prevOfPrev);
    }
}