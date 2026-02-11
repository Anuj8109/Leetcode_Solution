class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        Arrays.sort(piles);

        int start = 1,end = piles[piles.length - 1];
        long ans = Integer.MAX_VALUE;
        while (start <= end) {
            int mid = start + (end - start)/2;
            long currTime = 0;
            for(int i=0;i<piles.length;i++){
                currTime += (long)piles[i]/mid + (piles[i] % mid == 0 ? 0 : 1);
            }
            //System.out.println(mid +" " + currTime + " ");
            if(currTime > h){
                start = mid + 1;
            }
            else if(currTime <= h){
                end = mid - 1;
                ans = Math.min(ans,mid);
            }
        }
        return (int)ans;
    }
}