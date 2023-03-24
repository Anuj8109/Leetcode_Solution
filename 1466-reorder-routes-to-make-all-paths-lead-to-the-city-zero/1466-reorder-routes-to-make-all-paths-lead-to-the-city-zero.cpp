class Solution {
public:
    void helper(vector<unordered_map<int,vector<int>>> &graph,vector<bool> &visit,int &ans,int index){
        // if(visit[index]) return ;
        visit[index] = 1;
        for(auto i:graph[0][index]){
            if(!visit[i]) helper(graph,visit,ans,i);
        }
        for(auto i:graph[1][index]){
            if(!visit[i]){
                ans++;
                helper(graph,visit,ans,i);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& conn) {
        vector<unordered_map<int,vector<int>>> graph(2);
        vector<bool> visit(n,false);
        for(auto i:conn){
            graph[1][i[0]].push_back(i[1]);
            graph[0][i[1]].push_back(i[0]);
        }
        int ans = 0;
        helper(graph,visit,ans,0);
        return ans;
    }
};