class Solution {
public:
    bool check(int i,int j,int row,int col){
        return i >= 0 && j >= 0 && i < row && j < col;
    }
    void helper(vector<vector<char>>& grid, int x, int y){
        // visit[x][y] = true;
        int m = grid.size(), n = grid[0].size();
    
        grid[x][y] = '0';
        queue<pair<int,int>> que;
        que.push({x,y});
        vector<int> coor = {1,0,-1,0,1};
        while(!que.empty()){
            int p = que.front().first,q = que.front().second;
            que.pop();
            for(int i=0;i<4;i++){
                int dx = p + coor[i],dy = q + coor[i + 1];
                // cout<<dx<<" "<<dy<<endl;
                if(check(dx,dy,m,n) && grid[dx][dy] == '1'){
                    grid[dx][dy] = '0';
                    
                    que.push({dx,dy});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(),col = grid[0].size();
        // visit.assign(row + 1,vector<bool> (col + 1,false));
        int ans = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == '1'){
                    ans++;
                    helper(grid,i,j);
                }
            }
        }
        return ans;
    }
};