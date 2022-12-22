class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>> ans;
        sort(v.begin(),v.end());
        // vector<int> p = v[0];
        int end = v[0][1];
        int start = v[0][0];
        int n = v.size();
        int curr = 0;
        for(int i=1;i<n;i++){
            if(end >= v[i][0]){
                end = max(end,v[i][1]);
            }else{
                v[curr] = {start,end};
                curr++;
                end = v[i][1];
                start = v[i][0];
            }
        }
        // ans.push_back({start,end});
        v[curr] = {start,end};
        curr++;
        v.resize(curr);
        return v;
    }
};