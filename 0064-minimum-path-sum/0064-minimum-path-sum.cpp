class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
int row = grid.size();
        int col = grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i == 0 && j == 0) continue;
                else if(i == 0) grid[0][j] += grid[0][j-1];
                else if(j == 0) grid[i][0] += grid[i-1][0];
                else grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
                // cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
        return grid[row-1][col-1];
    }
};