class Solution {
public:
    vector<vector<int>> m;
    int profit(vector<int>& p,int i,bool buy){
        // cout<<i<<endl;
        if(i >= p.size()) return 0;
        if(m[buy][i] != -1) return m[buy][i];
        
        if(buy){
            int a = profit(p,i+1,0) - p[i];
            int b = profit(p,i+1,1);
            m[buy][i] = max(a,b);
        }else{
            int a = profit(p,i+2,1) + p[i];
            int b = profit(p,i+1,0);
            m[buy][i] = max(a,b);
        }
        return m[buy][i];
    }
    int maxProfit(vector<int>& prices) {
        m.assign(2,vector<int> (prices.size(),-1));
        return profit(prices,0,1);
    }
};