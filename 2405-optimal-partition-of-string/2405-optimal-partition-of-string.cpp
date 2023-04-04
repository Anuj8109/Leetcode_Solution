class Solution {
public:
    int partitionString(string s) {
        int i = 0,n = s.size();
        vector<bool> v(26,0);
        int ans = 1;
        while(i < n){
            if(v[s[i] - 'a']){
                ans++;
                v.assign(26,0);
            }else{
                v[s[i] - 'a'] = 1;
                i++;
            }
        }
        return ans;
    }
};