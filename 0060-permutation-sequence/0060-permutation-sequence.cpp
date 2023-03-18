class Solution {
public:
    string nextGreaterElement(string s) {
        // string s = to_string(num);
        int n = s.size();
        int i;
        for(i=n-1;i>0;i--){
            if(s[i] > s[i-1]) break; 
        }
        if(i == 0) return "-1";
        i--;
        // cout<<i<<endl;
        int j = i + 1;
        while(s[i] < s[j] && j < s.size()) j++;
        j--;
        swap(s[i],s[j]);
        // cout<<j<<endl;
        reverse(s.begin() + i + 1,s.end());
        return s;
    }
    string getPermutation(int n, int k) {
        string s = "";
        for(int i=0;i<n;i++) s += (i + '1');
        // return s;
        while(k > 1){
            s = nextGreaterElement(s);
            k--;
        }
        return s;
    }
};