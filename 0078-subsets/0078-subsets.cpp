class Solution {
public:
    void helper(vector<int> &nums,vector<vector<int>> &ans,int index){
        if(index == nums.size()) return ;
        
        int len = ans.size();
        for(int i=0;i<len;i++){
            ans[i].push_back(nums[index]);
            ans.push_back(ans[i]);
            ans[i].pop_back();
        }
        helper(nums,ans,index + 1);
        
    }
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> ans;
        ans.push_back({});
        helper(nums,ans,0);
        return ans;
    }
};