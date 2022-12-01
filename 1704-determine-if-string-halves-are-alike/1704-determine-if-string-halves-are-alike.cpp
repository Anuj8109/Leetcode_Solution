class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> us({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        int count = 0, n = s.size();
        for(int i=0;i<s.size();i++){
            if(us.find(s[i]) != us.end()){
                if(i >= n/2) count--;
                else count++;
            }
        }
        return count == 0;
    }
};