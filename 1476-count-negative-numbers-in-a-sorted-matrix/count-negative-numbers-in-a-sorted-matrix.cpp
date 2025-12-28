class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        int j = 0, i = m-1;
        int ans = 0;
        while(i >= 0 && j < n){
            while(j < n && grid[i][j] >= 0) j++;
            ans += n - j;
            // cout<<j<<" "<<ans<<endl;
            i--;
        }
        return ans;
    }
};