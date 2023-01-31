class Solution {
public:
    int fun(vector<int> nums,int s,int e,int k){
        int p = nums[s];
        swap(nums[s],nums[e]);
        int i = s;
        int j = s;
        while(j < e){
            if(nums[j] <= p){
                swap(nums[j],nums[i]);
                i++;
            }
            j++;
        }
        swap(nums[i],nums[e]);
        // cout<<s<<" "<<e<<" "<<i<<" "<<k<<endl;
        if(i == k) return p;
        if(i < k) return fun(nums,i+1,e,k);
        return fun(nums,s,i-1,k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        k = n - k;
        return fun(nums,0,n-1,k);
    }
};