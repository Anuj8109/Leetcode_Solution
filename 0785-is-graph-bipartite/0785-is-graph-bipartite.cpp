class Solution {
public:
    unordered_set<int> s1,s2;
    bool dfs(vector<vector<int>>& graph,vector<bool>& visit,int i,int s){
        if(visit[i]){
            return s == 1 ? s2.find(i) == s2.end() : s1.find(i) == s1.end();
            // if(s == 1 && s2.find(i) != s2.end()) return false;
            // if(s == 2 && s1.find(i) != s1.end()) return false;
            // return true;
        }
        // cout<<i<<" "<<s<<endl;
        visit[i] = true;
        if(s == 1) s1.insert(i);
        else s2.insert(i);
        int q = s == 1 ? 2 : 1;
        for(auto j:graph[i]){
            if(!dfs(graph,visit,j,q)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visit(n,false);
        
        for(int i=0;i<n;i++){
            if(!visit[i]){
                // cout<<i<<endl;
                if(!dfs(graph,visit,i,1)) return false;
            }
        }
        return true;
    }
};