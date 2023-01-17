class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int zeros = 0,ones = 0;
        for(auto i:s){
            if(i == '0') zeros++;
            // else ones++;
        }
        
        int ans = zeros;
        for(int i:s){
            if(i == '0') zeros--;
            else ones++;
            ans = min(ans,zeros + ones);
        }
        return ans;
    }
};