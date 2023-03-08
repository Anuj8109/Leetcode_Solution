class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start = 1;
        int end = *max_element(piles.begin(),piles.end());
        if(n == h) return end;
        int ans = INT_MAX;
        while(start <= end){
            int mid = (start + end)/2;
            // cout<<mid<<endl;
            int take = 0;
            for(int i=0;i<n && take <= h;i++){
                take += piles[i]/mid;
                if(piles[i] % mid) take++;
            }
            if(take <= h){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};