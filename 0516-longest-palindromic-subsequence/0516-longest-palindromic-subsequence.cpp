class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string q = s;
        reverse(q.begin(),q.end());
        int n = s.size();
        int mlen = 0;
        vector<vector<int>> v(n+1,vector<int> (n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == q[j-1]){
                    // v[i][j] = max({1 + v[i-1][j-1], v[i-1][j], v[i][j-1]});
                    v[i][j] = 1 + v[i-1][j-1];
                }else{
                    // v[i][j] = max({v[i-1][j-1],v[i-1][j],v[i][j-1]});
                    v[i][j] = max(v[i-1][j],v[i][j-1]);
                }
                if(mlen < v[i][j]) mlen = v[i][j];
                // cout<<v[i][j]<<" ";
            }
            // cout<<endl;
        }
        return v[n][n];
    }
};