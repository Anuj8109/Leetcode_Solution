class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        for(auto i:s){
            if(i == '*'){
                if(ans.size()) ans.pop_back();
            }else{
                ans += i;
            }
        }
        return ans;

    }
};