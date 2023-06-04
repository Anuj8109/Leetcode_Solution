class Solution {
public:
    // vector<bool> visit;
    void helper(vector<vector<int>>& con,int i,int n){
        // visit[i] = true;
        if(con[i][i] == 0) return ;
        // cout<<i<<endl;
        con[i][i] = 0;
        for(int j=0;j<n;j++){
            if(con[i][j] ){
                helper(con,j,n);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& con) {
        int n = con.size();
        // vector<bool> visit(n,false);
        // visit.assign(n,false);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(con[i][i] == 1){
                ans++;
                helper(con,i,n);
            }
        }
        return ans;
    }
};