class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>>& ans,int index,int last){
        if(index == nums.size()) return ;
        // cout<<index<<" ";
        int len = ans.size();
        int start = 0;
        if(index > 0 && nums[index] == nums[index - 1]) start = last;
        // cout<<start<<endl;
        for(int i=start;i<len;i++){
            ans[i].push_back(nums[index]);
            ans.push_back(ans[i]);
            ans[i].pop_back();
        }
        // index++;
        // while(index < nums.size() && nums[index] == nums[index - 1]){
        //     int len = ans.size();
        //     for(int i=start;i<len;i++){
        //         ans[i].push_back(nums[index]);
        //         ans.push_back(ans[i]);
        //         ans[i].pop_back();
        //     }
        //     start = len;
        //     index++;
        // }
        helper(nums,ans,index + 1,len);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        ans.push_back({});
        helper(nums,ans,0,-1);
        return ans;
    }
};