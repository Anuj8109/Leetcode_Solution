class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int e = nums.size() - 1,s = 0;
        while(s <= e){
            // cout<<s<<" "<<e<<endl;
            int mid = (s + e)/2;
            if(mid & 1){
                if(nums[mid] != nums[mid - 1]) e = mid - 1;
                else s = mid + 1;
            }else{
                if(nums[mid] != nums[mid + 1]) e = mid - 1;
                else s = mid + 1;
            }
        }
        return nums[s];
    }
};