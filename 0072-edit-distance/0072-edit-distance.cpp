class Solution {
public:
    int minDistance(string w1, string w2) {
        int p = w1.size();
        int q = w2.size();
        vector<vector<int>> v(p+1,(vector<int> (q+1,0)));
        
        for(int i=0;i<=p;i++){
            v[i][0] = i;
        }
        for(int j=0;j<=q;j++){
            v[0][j] = j;
        }
        for(int i=1;i<=p;i++){
            for(int j=1;j<=q;j++){
                if(w1[i-1] == w2[j-1]){
                    v[i][j] = v[i-1][j-1];
                    v[i][j] = min(v[i][j],1 + min(v[i-1][j],v[i][j-1]));
                }else{
                    v[i][j] = 1 + min(v[i-1][j-1],min(v[i-1][j],v[i][j-1]));
                }
                // cout<<v[i][j]<<" ";
            }
            // cout<<endl;
        }
        return v[p][q];
    }
};