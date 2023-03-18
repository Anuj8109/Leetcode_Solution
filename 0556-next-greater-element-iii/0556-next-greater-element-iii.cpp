class Solution {
public:
    int nextGreaterElement(int num) {
        string s = to_string(num);
        int n = s.size();
        int i;
        for(i=n-1;i>0;i--){
            if(s[i] > s[i-1]) break; 
        }
        if(i == 0) return -1;
        i--;
        // cout<<i<<endl;
        int j = i + 1;
        while(s[i] < s[j] && j < s.size()) j++;
        j--;
        swap(s[i],s[j]);
        // cout<<j<<endl;
        reverse(s.begin() + i + 1,s.end());
        long long p = stoll(s);
        if(p > INT_MAX) return -1;
        return p;
    }
};