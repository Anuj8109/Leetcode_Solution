class Solution {
public:
    bool canPlaceFlowers(vector<int>& flow, int n) {
        int i = 0;
        int len = flow.size();
        flow.push_back(0);
        while(i < len && n > 0){
            // cout<<i<<endl;
            if(flow[i] == 1){
                i += 2;
                // continue;
            }
            else if(flow[i+1] == 0){
                i += 2;
                n--;
                // continue;
            }
            else i++;
        }
        return n == 0;
    }
};