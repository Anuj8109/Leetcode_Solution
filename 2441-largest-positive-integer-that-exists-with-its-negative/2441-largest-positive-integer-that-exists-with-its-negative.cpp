class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int left = 0,right = nums.size() - 1;
        while(left < right){
            if(nums[left] > 0) return -1;
            if(abs(nums[left]) < nums[right]) right--;
            else if(abs(nums[left]) > nums[right]) left++;
            else return nums[right];
        }
        return -1;
    }
};