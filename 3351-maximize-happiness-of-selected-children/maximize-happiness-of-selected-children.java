class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int h:happiness){
            pq.add(h);
            if(pq.size() > k) pq.poll();
        }
        long ans = 0;
       
        for(;k>0 && !pq.isEmpty();k--){
            // System.out.println(pq);
            ans += Math.max(pq.poll() - k + 1, 0);
        }
        return ans;
    }
}