class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& can, int extra) {
        int n = can.size();
        int maxi = can[0];
        for(int i=0;i<n;i++) maxi = max(maxi,can[i]);
        vector<bool> ans(n,0);
        for(int i=0;i<n;i++){
            if(can[i] + extra >= maxi) ans[i] = 1;
        }
        return ans;
    }
};