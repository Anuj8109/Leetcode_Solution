class Solution {
public:
    vector<vector<bool>> visit;
    bool helper(vector<vector<int>>& grid,int i,int j){
        int m = grid.size(),n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n ) return false;
        if(grid[i][j]) return true;
        // if(visit[i][j]) return true;
        grid[i][j] = 1;
        // if(!helper(grid,i+1,j)) return false;
        // if(!helper(grid,i-1,j)) return false;
        // if(!helper(grid,i,j+1)) return false;
        // if(!helper(grid,i,j-1)) return false;
        bool p = helper(grid,i+1,j),q = helper(grid,i-1,j),r = helper(grid,i,j-1),s = helper(grid,i,j+1);
        if(p && q && r && s) return true;
        return false;
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(),n = grid[0].size();
        // v.assign(m,vector<bool> (n,false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 0 && helper(grid,i,j)) ans++;
            }
        }
        return ans;
    }
};