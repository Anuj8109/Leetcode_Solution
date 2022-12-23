class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int rows = m.size();
        int cols = m[0].size();
        int p = rows-1, q = 0;
        while(p >= 0 && q < cols){
            if(m[p][q] == t) return 1;
            else if(m[p][q] < t) q++;
            else p--;
        }
        return 0;
    }
};