class Solution {
public:
    unordered_set<int> s1,s2;
    bool dfs(vector<vector<int>> &v,vector<bool>& visit,int i,bool s){
        if(visit[i]){
            if(s && s2.find(i) != s1.end()) return false;
            if(!s && s1.find(i) != s2.end()) return false;
            return true;
        }
        // cout<<i<<" "<<s<<endl;
        visit[i] = true;
        if(s){
            if(s2.find(i) != s2.end()) return false;
            else s1.insert(i);
        }
        // else s1.insert(i);
        if(!s){
            if(s1.find(i) != s1.end()) return false;
            else s2.insert(i);
        }
        bool q = !s;
        for(auto j:v[i]){
            if(dfs(v,visit,j,q) == false) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> v(n+1);
        for(auto i:dislikes){
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
        }
        vector<bool> visit(n,false);
        for(int i=1;i<=n;i++){
            // 
            if(!visit[i]){
                // cout<<i<<endl;
                if(s1.find(i) == s1.end()){
                    if(!dfs(v,visit,i,true)) return false;
                }
                else{
                    if(!dfs(v,visit,i,true)) return false;
                }
            }
        }
        return true;
    }
};