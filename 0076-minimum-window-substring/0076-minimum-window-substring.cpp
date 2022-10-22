class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        vector<int> v(256,0);
        int diff = 0;
        for(auto i:t){
            if(v[i] == 0) diff++;
            v[i]++;
        }
        int start = 0;
        string ans = "";
        vector<int> p(256,0);
        for(int i=0;i<s.size();i++){
            p[s[i]]++;
            if(p[s[i]] == v[s[i]]) diff--;
            if(diff == 0){
                while(p[s[start]] != v[s[start]]){
                    p[s[start]]--;
                    // cout<<p[s[start]]<<" "<<v[s[start]]<<" "<<s[start]<<endl;
                    start++;
                }
                if(ans.size() == 0 || ans.size() > i - start + 1){
                    ans = s.substr(start,i - start + 1);
                }
                p[s[start]]--;
                diff++;
                start++;
                // cout<<start<<" "<<i<<" "<<ans<<endl;
            }
        }
        return ans;
    }
};