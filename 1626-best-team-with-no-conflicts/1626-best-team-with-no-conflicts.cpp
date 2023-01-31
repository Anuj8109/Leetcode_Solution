class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v;
        for(int i=0;i<ages.size();i++){
            v.push_back({ages[i],scores[i]});
        }
        sort(v.begin(),v.end());
        vector<int> dp(ages.size(),0);
        dp[0] = v[0].second;
        int ans = dp[0];
        for(int i=1;i<ages.size();i++){
            dp[i] = v[i].second;
            for(int j=i-1;j>=0;j--){
                if(v[j].second <= v[i].second){
                    dp[i] = max(dp[j] + v[i].second,dp[i]);
                }
            }
            ans = max(ans,dp[i]);
        }
        // for(auto i:dp) cout<<i<<" ";
        // cout<<endl;
        return ans;
    }
};