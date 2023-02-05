class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int p = s1.size();
        int q = s2.size();
        if(q < p) return false;
        vector<int> v(26,0);
        for(auto i:s1) v[i-'a']++;
        
        for(int i=0;i<p;i++){
            v[s2[i] - 'a']--;
        }
        bool f = true;
        for(int i=0;i<26;i++){
            if(v[i] != 0){
                f = false;
                break;
            }
        }
        if(f) return true;
        for(int i=p;i<q;i++){
            if(s2[i] == s2[i-p]) continue;
            v[s2[i-p] - 'a']++;
            v[s2[i] - 'a']--;
            bool f = true;
            for(int i=0;i<26;i++){
                if(v[i] != 0){
                    f = false;
                    break;
                }
            }
            if(f) return true;
        }
        return false;
    }
};