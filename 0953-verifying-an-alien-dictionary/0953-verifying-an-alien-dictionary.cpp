class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> m;
        // int count
        for(int i=0;i<26;i++){
            m[order[i]] = i;
        }
        for(int i=0;i<words.size() - 1;i++){
            string p = words[i];
            string q = words[i+1];
            int j = 0;
            while(j < p.size() && j < q.size()){
                if(p[j] != q[j] ){
                    if(m[p[j]] < m[q[j]]) break;
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