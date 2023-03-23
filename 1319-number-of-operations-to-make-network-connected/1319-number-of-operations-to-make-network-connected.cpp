class Solution {
public:
    vector<bool> visit;
    void dfs(vector<vector<int>>& v,int i){
        if(visit[i]) return;
        visit[i] = true;
        // cout<<v[i].size()<<" "<<i<<endl;
        for(int j=0;j<v[i].size();j++){
            dfs(v,v[i][j]);
            // cout<<v[i][j]<<" "<<i<<endl;
        }
    }
    int makeConnected(int n, vector<vector<int>>& conn) {
        int cables = conn.size();
        vector<vector<int>> v(n);
        if(n - 1> cables) return -1;
        for(auto i:conn){
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
        }
        visit.assign(n,false);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!visit[i]){
                ans++;
                dfs(v,i);
                // cout<<i<<endl;
            }
        }
        return ans - 1;
    }
};