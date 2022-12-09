class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long sum = 0;
        for(auto i:nums) sum += i;
        int n = nums.size();
        long curr = 0;
        int ansDiff = INT_MAX;
        int ansInd = 0;
        
        for(int i=0;i<nums.size() - 1;i++){
            sum -= nums[i];
            curr += nums[i];
            int q = sum/(n - i - 1);
            int p = curr/(i + 1);
            if(abs(p -q) < ansDiff){
                ansInd = i;
                ansDiff = abs(p - q);
            }
        }
        curr += nums[n-1];
        if(curr/n < ansDiff) ansInd = n - 1;
        return ansInd;
    }
};