class Solution {
public:
    vector<vector<int>> v;
    int helper(vector<vector<int>>& piles,int k,int curr){
        if(curr == piles.size() || k == 0) return 0;
        // cout<<curr<<" "<<k<<endl;
        if(v[curr][k] != -1) return v[curr][k];
        // cout<<curr<<" "<<k<<endl;
        int ans = helper(piles,k,curr+1);
        int sum = 0;
        int len = piles[curr].size();
        for(int i=0;i<min(k,len);i++){
            sum += piles[curr][i];
            int p = sum + helper(piles,k - i - 1,curr+1);
            // cout<<i<<" "<<k<<" "<<p<<endl;
            if(p > ans) ans = p;
        }
        return v[curr][k] = ans;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        int n = piles.size();
        v.assign(n,vector<int> (k+1,-1));
        return helper(piles,k,0);
// //         for(int i=n-1;i>=0;i--){
// //             if(i == n-1) v[i][0] = 0;
// //             else v[i][0] = v[i+1][0];
// //             for
            
// //         }
//         int f = 0;
//         int x = piles[0].size();
//         for(int j=0;j<=min(k,x);j++){
//             v[0][j] = f;
//             if(j != x) f += piles[0][j];
            
//         }
//         for(int i=1;i<n;i++){
//             // v[i][0] = 0;
//             int x = piles[i].size();
//             for(int j=0;j<=k;j++){
//                 int sum = 0;
//                 if(j > x){
//                     v[i][j] = v[i][j-1];
//                     continue;
//                 }
//                 for(int p=0;p<=j;p++){
//                     // cout<<i<<" "<<j<<" "<<p<<endl;
//                     v[i][j] = max(sum + v[i-1][j-p],v[i][j]);
//                     if(p != x) sum += piles[i][p];
//                 }
//             }
//         }
//         int ans = 0;
//         for(int i=0;i<=k;i++){
//             ans = max(ans,v[n-1][i]);
//         }
//         return ans;
    }
};