class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto i:roads){
            graph[i[0]].push_back({i[1],i[2]});
            graph[i[1]].push_back({i[0],i[2]});
        }
        vector<bool> visit(n+1,false);
        queue<int> q;
        q.push(1);
        visit[1] = 0;
        int ans = INT_MAX;
        while(!q.empty()){
            auto p = q.front();q.pop();
            for(auto &[v,dis]:graph[p]){
                ans = min(ans,dis);
                if(visit[v] == 0){
                    visit[v] = 1;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};