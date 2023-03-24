class Solution {
public:
    void helper(vector<vector<int>> &v1,vector<vector<int>> &v2,vector<bool> &visit,int &ans,int index){
        // if(visit[index]) return ;
        visit[index] = 1;
        for(auto i:v2[index]){
            if(!visit[i]) helper(v1,v2,visit,ans,i);
        }
        for(auto i:v1[index]){
            if(!visit[i]){
                ans++;
                helper(v1,v2,visit,ans,i);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& conn) {
        vector<vector<int>> v1(n);
        vector<vector<int>> v2(n);
        vector<bool> visit(n,false);
        for(auto i:conn){
            v1[i[0]].push_back(i[1]);
            v2[i[1]].push_back(i[0]);
        }
        int ans = 0;
        helper(v1,v2,visit,ans,0);
        return ans;
    }
};