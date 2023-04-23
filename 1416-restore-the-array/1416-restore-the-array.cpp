class Solution {
public:
    int mod = 1e9 +  7;
    int helper(string &s,int k,vector<int> &dp,int index){
        if(index >= s.size()) return 1;
        else if(dp[index] != -1) return dp[index];
        else if(s[index] == '0') return 0;
        long p;
        long ans = 0;
        for(int i=1;i + index <= s.size();i++){
            p = stol(s.substr(index,i));
            if(p <= k){
                ans = (ans + helper(s,k,dp,i + index)) % mod;
            }else break;
        }
        return dp[index] = ans;
    }
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size(),-1);
        return helper(s,k,dp,0);
    }
};