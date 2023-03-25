class Solution {
public:
    long long count(vector<vector<int>> &graph,vector<bool> &visit,int index){
        if(visit[index]) return 0;
        visit[index] = 1;
        long long ans = 1;
        for(auto i:graph[index]){
            if(!visit[i]) ans += count(graph,visit,i);
            // ans++;
        }
        return ans;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto i:edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<bool> visit(n,false);
        long long ans = 0,p;
        for(int i=0;i<n;i++){
            if(!visit[i]){
                p = count(graph,visit,i);
                // cout<<p<<endl;
                ans += p*(n - p);
            }
        }
        return ans/2;
    }
};