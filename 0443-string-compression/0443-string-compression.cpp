class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 0;
        int j = 0;
        int n = chars.size();
        for(int i=0;i<chars.size();){
            count = 0;
            char p = chars[i];
            while(i < n && p == chars[i]){
                i++;
                count++;
            }
            if(count == 1){
                chars[j++] = p;
            }else{
                chars[j++] = p;
                auto q = to_string(count);
                for(auto k:q) chars[j++] = k;
                // chars[j++] = count + '0';
            }
        }
        return j;
    }
};