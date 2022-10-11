class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1 = INT_MAX, m2 = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i] <= m2) m2 = nums[i];
            else if(nums[i] <= m1) m1 = nums[i];
            else return 1;
        }
        return 0;
        // int len = nums.size();
        // vector<int> v(len);
        // v[0] = nums[0];
        // for(int i=1;i<nums.size();i++){
        //     v[i] = min(v[i-1],nums[i]);
        //     // cout<<v[i]<<" ";
        // }
        // // cout<<endl;
        // int large = nums[len - 1];
        // for(int i = len - 2;i > 0;i--){
        //     if(nums[i] >= large) large = nums[i];
        //     else if(nums[i] > v[i-1]) return 1;
        //     // else cout<<nums[i]<<" "<<v[i-1]<<endl;
        // }
        // return 0;
    }
};