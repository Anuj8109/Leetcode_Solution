class Solution {
public:
    string convert(string s, int row) {
        if(row ==  1) return s;
        string ans = "";
        int n = s.size();
        int i = 0,j;
        while(i < row){
            j = i;
            if(i == 0 || i == row - 1){
                while(j < n){
                    ans += s[j];
                    j += (row - 1)*2;
                }
            }else{
                int total = 2*(row - 1);
                while(j < n){
                    ans += s[j];
                    j += (row - i - 1)*2;
                    if(j < n) ans +=s[j];
                    j += total - (row - i - 1)*2;
                }
            }
            i++;
        }
        return ans;
    }
};