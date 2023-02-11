class Solution {
public:
    int strStr(string hay, string ndl) {
        if(ndl.size() == 0) return 0;
        int si = ndl.size();
        int n = hay.size();
        if(n < si) return -1;
        int i = 0;
        
        while(i < n - si + 1){
            if(hay[i] == ndl[0]){
                string p = hay.substr(i,si);
                if(ndl == p) return i;
                
            }
            i++;
        }
        return -1;
    }
};