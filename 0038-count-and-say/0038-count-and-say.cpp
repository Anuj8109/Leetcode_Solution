class Solution {
public:
    string countAndSay(int n) {
        string s;
        char c = '0' + 1;
        s.push_back(c);
        if(n==1){
            return s;
        }else{
            while(n>1){
                char lChar = s[0];
                string ans;
                int i = 1;
                int c = 0;
                int count =1;
                while(i<s.length()){
                    if(s[i] != lChar){
                        char f = '0'+ count;
                        ans.push_back(f);
                        ans.push_back(lChar);
                        // cout<<count<<lChar;
                        lChar = s[i];
                        count = 1;
                    }else{
                        count++;
                    }
                    i++;
                }
                // cout<<count<<lChar<<endl;
                char f = '0' + count;
                ans.push_back(f);
                ans.push_back(lChar);
                s = ans;
                n--;
            }
        }
        return s;
    }
};