class Solution {
public:
    int compress(vector<char>& chars) {
        int j = 0;
        int n = chars.size();
        for(int i=0;i<chars.size();i++){
            int count = 1;
            while(i + 1 < n && chars[i+1] == chars[i]){
                i++;
                count++;
            }
            if(count == 1){
                chars[j++] = chars[i];
            }else{
                chars[j++] = chars[i];
                auto q = to_string(count);
                for(auto k:q) chars[j++] = k;
            }
        }
        return j;
    }
};