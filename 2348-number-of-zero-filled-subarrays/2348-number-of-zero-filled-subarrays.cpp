class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int i = 0;
        int n = nums.size();
        while(i < n){
            int count = 0;
            while(i < n && nums[i] == 0){
                count++;
                i++;
            }
            ans += ((long long)count*(count + 1))/2;
            i++;
        }
        return ans;
    }
};