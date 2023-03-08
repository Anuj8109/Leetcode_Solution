class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start = 1;
        int end = 1e9;
        while(start < end){
            int mid = (start + end)/2;
            int take = 0;
            for(int i=0;i<n;i++){
                take += piles[i]/mid;
                if(piles[i] % mid) take++;
            }
            if(take <= h) end = mid;
            else start = mid + 1;
        }
        return start;
    }
};