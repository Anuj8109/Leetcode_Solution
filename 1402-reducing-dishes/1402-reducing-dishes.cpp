class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(),v.end());
        int n = v.size();
        if(v[n-1] < 0) return 0;
        int p = lower_bound(v.begin(),v.end(),0) - v.begin();
        int sum = 0;
        int ans = 0,j = 1;
        // cout<<p<<endl;
        for(int i=p;i<n;i++){
            sum += v[i];
            ans += (v[i])*j;
            j++;
        }
        p--;
        while(p >= 0 && sum + v[p] > 0){
            ans += sum + v[p];
            sum += v[p];
            p--;
        }
        return ans;
    }
};