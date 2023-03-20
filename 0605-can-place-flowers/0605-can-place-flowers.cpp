class Solution {
public:
    bool canPlaceFlowers(vector<int>& flow, int n) {
        int i = 0;
        int len = flow.size();
        while(i < len && n > 0){
            // cout<<i<<endl;
            if(flow[i] == 1){
                i += 2;
                continue;
            }
            else if((i + 1 < len && flow[i+1] == 0) || i + 1 == len){
                i += 2;
                n--;
                continue;
            }
            else i++;
        }
        return n == 0;
    }
};