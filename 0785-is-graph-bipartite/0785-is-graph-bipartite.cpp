class Solution {
public:
    unordered_set<int> s1,s2;
    vector<int> v1,v2;
    Solution(){
        v1.assign(100,0);
        v2.assign(100,0);
    }
    bool dfs(vector<vector<int>>& graph,vector<bool>& visit,int i,int s){
        if(visit[i]){
            return s == 0 ? !v2[i] : !v1[i];
        }
        // cout<<i<<" "<<s<<endl;
        visit[i] = true;
        s == 0 ? v1[i] = 1 : v2[i] = 1; 
        // int q = s == 1 ? 2 : 1;
        for(auto j:graph[i]){
            if(!dfs(graph,visit,j,!s)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visit(n,false);
        
        for(int i=0;i<n;i++){
            if(!visit[i]){
                // cout<<i<<endl;
                if(!dfs(graph,visit,i,0)) return false;
            }
        }
        return true;
    }
};