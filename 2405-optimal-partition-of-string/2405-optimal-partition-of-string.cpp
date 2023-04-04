class Solution {
public:
    int partitionString(string s) {
        int i = 0,n = s.size();
        vector<int> v(26,0);
        int ans = 1;
        while(i < n){
            if(v[s[i] - 'a']){
                ans++;
                v.assign(26,0);
            }else{
                v[s[i] - 'a']++;
                i++;
            }
        }
        return ans;
    }
};