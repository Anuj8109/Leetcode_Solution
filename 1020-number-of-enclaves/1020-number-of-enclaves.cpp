class Solution {
public:
    void helper(vector<vector<int>>& grid,int i,int j){
        int m = grid.size(),n = grid[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) return ;
        grid[i][j] = 0;
        vector<int> coor{1,0,-1,0,1};
        for(int k=0;k<4;k++){
            helper(grid,i + coor[k],j + coor[k + 1]);
        }
        // helper(grid,i+1,j);
        // helper(grid,i-1,j);
        // helper(grid,i,j+1);
        // helper(grid,i,j-1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1) helper(grid,i,j);
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]) ans++;
            }
        }
        return ans;
    }
};