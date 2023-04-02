class Solution {
public:
    int bs(vector<int> &potions,long long &succ,int mul){
        int n = potions.size();
        if((1LL)*potions[0]*mul >= succ) return n;
        else if((1LL)*potions[n-1]*mul < succ) return 0;
        int s = 0,e = potions.size() - 1;
        int ans = 0;
        long long temp;
        while(s < e){
            int mid = (s + e)/2;
            temp = (1LL)*potions[mid]*mul;
            if(temp < succ) s = mid + 1;
            else e = mid;
            // cout<<s<<" "<<e<<endl;
        }
        return potions.size() - s;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        // cout<<bs(potions,success,spells[1])<<endl;
        int n = spells.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = bs(potions,success,spells[i]);
        }
        return ans;
    }
};