class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i = 0;
        int n = word1.size(), m = word2.size();
        while(i < n && i < m){
            ans += word1[i];
            ans += word2[i];
            i++;
        }
        if(i < n) ans += word1.substr(i);
        if(i < m) ans += word2.substr(i);
        return ans;
    }
};