class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        int len = happiness.length;
        long ans = 0;
        for(int i=0;i<k;i++){
            ans += Math.max(happiness[len - i - 1] - i, 0);
        }
        return ans;
        // PriorityQueue<Integer> pq = new PriorityQueue<>();
        // for(int h:happiness){
        //     pq.add(h);
        //     if(pq.size() > k) pq.poll();
        // }
        // long ans = 0;
       
        // for(;k>0 && !pq.isEmpty();k--){
        //     // System.out.println(pq);
        //     ans += Math.max(pq.poll() - k + 1, 0);
        // }
        // return ans;
    }
}