class Solution {
public:
    // vector<vector<int>> v;
    int helper(unordered_map<int,vector<int>>& m,vector<int>& it,int i){
        // if(v[i].size() == 0) return ;
        // ans += it[i];
        int p = 0;
        for(auto j:m[i]){
            p = max(helper(m,it,j),p);
        }
        return p + it[i];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // vector<vector<int>> v(n);
        unordered_map<int,vector<int>> m;
        // v.assign(n,vector<int> {});
        for(int i=0;i<n;i++){
            if(i != headID){
                m[manager[i]].push_back(i);
            }
        }
        return helper(m,informTime,headID);
    }
};