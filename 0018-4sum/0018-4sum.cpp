class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j != i+1 && nums[j] == nums[j-1]) continue;
                int l = j + 1;
                int r = n - 1;
                long long int curr;
                while(l < r){
                    curr = (long)nums[i] + (long)nums[j] + (long)nums[l] + (long)nums[r];
                    if(tar == curr){
                        vector<int> v = {nums[i],nums[j],nums[l],nums[r]};
                        ans.push_back(v);
                        l++;
                        while(nums[l] == nums[l - 1] && l < r) l++;
                        r--;
                        while(nums[r] == nums[r + 1] && l < r) r--;
                        // if(ans.size() == 0) ans.push_back(v);
                        // else if(ans.size() && ans.back() != v) ans.push_back(v);
                        // l++;
                        // r--;
                    }else if(curr < tar) l++;
                    else r--;
                }
            }
        }
        return ans;
    }
};