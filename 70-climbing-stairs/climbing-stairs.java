class Solution {
    public int climbStairs(int n) {
        int prevOfPrev = 0;
        int prev = 1;
        while(n-- > 0){
            int curr = prev + prevOfPrev;
            prevOfPrev = prev;
            prev = curr;
        }
        return prev;
    }
}