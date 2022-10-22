class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0,start = 0;
        int k = 0;
        while(i < nums.size()){
            if(nums[i] != val){
                swap(nums[i],nums[start++]);
                k++;
            }
            i++;
        }
        return k;
    }
};