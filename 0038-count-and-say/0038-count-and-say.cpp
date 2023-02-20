class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while(n>1){
            string ans = "";
            int i = 1;
            int count =1;
            while(i<s.length()){
                if(s[i] != s[i-1]){
                    ans += to_string(count) + s[i-1];
                    count = 1;
                }else count++;
                i++;
            }
            ans += to_string(count) + s[i-1];
            s = ans;
            n--;
        }
        return s;
    }
};