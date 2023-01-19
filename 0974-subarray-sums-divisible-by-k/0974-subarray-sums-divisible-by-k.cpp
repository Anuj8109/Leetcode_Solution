class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0,n = nums.size(),ans = 0;
        vector<int> m(k,0);
        m[0] = 1;
        int p;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum < k) sum += k;
            sum %= k;
            p = sum;
            if(p < 0) p += k;
            ans += m[p];
            m[p]++;
        }
        return ans;
    }
};