class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int ans = 0;
        vector<vector<int>> v(n + 1,vector<int> (n+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i] == s[n-1-j]) v[i + 1][j + 1] = 1 + v[i][j];
                else v[i + 1][j + 1] = max(v[i + 1][j],v[i][j+1]);
                // cout<<v[i+1][j+1]<<" ";
            }
            // cout<<endl;
        }
        return n - v[n][n];
    }
};