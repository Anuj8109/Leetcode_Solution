class Solution {
public:
    vector<vector<int>> v;
    int helper(vector<int>& it,int i){
        // if(v[i].size() == 0) return ;
        // ans += it[i];
        int p = 0;
        for(auto j:v[i]){
            p = max(helper(it,j),p);
        }
        return p + it[i];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // vector<vector<int>> v(n);
        v.assign(n,vector<int> {});
        for(int i=0;i<n;i++){
            if(i != headID){
                v[manager[i]].push_back(i);
            }
        }
        return helper(informTime,headID);
    }
};