class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int p = m.size();
        int q = m[0].size();
        int e = p*q - 1;
        int s = 0;
        while(s <= e){
            int mid = (s + e)/2;
            int x = m[mid/q][mid%q];
            if(x < t) s = mid + 1;
            else if(x > t) e = mid - 1;
            else return 1;
        }
        return 0;
    }
};