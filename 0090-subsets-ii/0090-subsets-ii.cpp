class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>>& ans,int index){
        if(index >= nums.size()) return ;
        int n = ans.size();
        vector<vector<int>> temp;
        int start = ans.size();
        for(int i=0;i<n;i++){
            // auto p = ans[i];
            // p.push_back(nums[index]);
            ans[i].push_back(nums[index]);
            // temp.push_back(p);
            ans.push_back(ans[i]);
            ans[i].pop_back();
        }
        index++;
        while(index < nums.size() && nums[index] == nums[index - 1]){
            int len = ans.size();
            for(int i=start;i<len;i++){
                ans[i].push_back(nums[index]);
                ans.push_back(ans[i]);
                ans[i].pop_back();
            }
            start = len;
            index++;
        }
        helper(nums,ans,index);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        ans.push_back({});
        helper(nums,ans,0);
        // for(int i=0;i<nums.size();i++){
        //     vector<int> p = {};
        //     helper(nums,ans,p,i);
        // }
        
        return ans;
    }
};