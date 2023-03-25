class Solution {
public:
    int helper(unordered_map<int,vector<int>> &graph,string &s,int &ans,int index){
        if(graph.count(index) == 0) return 1;
        int current = 0;
        for(auto i:graph[index]){
            int temp = helper(graph,s,ans,i);
            if(s[i] != s[index]){
                ans = max(ans,current + temp + 1);
                current = max(current,temp);
            }
        }
        // current++;
        return current + 1;
    }
    int longestPath(vector<int>& par, string s) {
        int n = par.size();
        unordered_map<int,vector<int>> v(n);
        for(int i=1;i<n;i++){
            v[par[i]].push_back(i);
        }
        int ans = 0;
        return max(ans,helper(v,s,ans,0));
    }
};