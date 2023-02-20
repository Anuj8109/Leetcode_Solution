class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i = 0;
        int j = 0;
        int p = v1.size();
        int q = v2.size();
        while(i < p || j < q){
            long long val1 = 0;
            long long val2 = 0;
            while(i < p && v1[i] != '.'){
                val1 = val1*10 + v1[i] - '0';
                i++;
            }
            while(j < q && v2[j] != '.'){
                val2 = val2*10 + v2[j] - '0';
                j++;
            }
            // cout<<val1<<" "<<val2<<endl;
            if(val1 > val2) return 1;
            else if(val1 < val2) return -1;
            i++;
            j++;
            
        }
        // if(i )
        return 0;
    }
};