class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<words.size() - 1;i++){
            string p = words[i];
            string q = words[i+1];
            int j = 0;
            while(j < p.size() && j < q.size()){
                if(p[j] != q[j] ){
                    if(order.find(p[j]) < order.find(q[j])) break;
                    else return 0;
                }
                // cout<<j<<endl;
                j++;
            }
            
            if(j < p.size() && j == q.size()) return 0;
        }
        return 1;
    }
};