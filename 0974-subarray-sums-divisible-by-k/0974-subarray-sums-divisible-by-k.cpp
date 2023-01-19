class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0,n = nums.size(),ans = 0;
        map<int,int> m;
        m[0] = 1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum < k) sum += k;
            sum %= k;
            int p = sum;
            if(p < 0) p += k;
            ans += m[p];
            m[p]++;
        }
        return ans;
    }
};