class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(days[n - 1] + 1);
        dp[0] = 0;
        int j = 0;
        for(int i=1;i<=365 && j < n;i++){
            if(i == days[j]){
                dp[i] = min({dp[i-1] + costs[0],dp[max(0,i-7)] + costs[1],dp[max(0,i-30)] + costs[2]});
                // dp[i] = dp[i-1] + costs[0];
                // dp[i] = min(dp[i],);
                // dp[i] = min(dp[i],);
                j++;
            }else dp[i] = dp[i-1];
        }
        return dp[days[n-1]];
        // for(int i=0;i<n;i++){
        //     int p = days[i];
        //     dp[i + 1] = dp[i] + costs[0];
        //     dp[i + 1] = min(dp[i + 1], dp[max(0,i - 7)] + costs[1]);
        //     dp[i + 1] = min(dp[i + 1], dp[max(0,i - 30)] + costs[2]);
        // }
        // return dp[n - 1];
    }
};