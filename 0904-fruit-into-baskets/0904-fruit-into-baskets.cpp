class Solution {
public:
    int totalFruit(vector<int>& f) {
        int a = f[0];
        int count = 1;
        vector<vector<int>> v;
        for(int i=1;i<f.size();i++){
            if(f[i] == a) count++;
            else{
                v.push_back({a,count});
                a = f[i];count = 1;
            }
        }
        v.push_back({a,count});
        int p = v[0][1];
        if(v.size() == 1) return p;
        int q = v[1][1];
        int ans = p + q;
        for(int i=2;i<v.size();i++){
            if(v[i-2][0] == v[i][0]){
                p += v[i][1];
            }else{
                p = v[i-1][1];
                q = v[i][1];
            }
            ans = max(ans,p + q);
        }
        return ans;
    }
};