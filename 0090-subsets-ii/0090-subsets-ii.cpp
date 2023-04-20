class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>>& ans,int index){
        if(index >= nums.size()) return ;
        int n = ans.size();
        vector<vector<int>> temp;
        for(int i=0;i<n;i++){
            auto p = ans[i];
            p.push_back(nums[index]);
            temp.push_back(p);
            ans.push_back(p);
        }
        index++;
        // cout<<nums[index]<<" "<<nums[index - 1]<<endl;
        while(index < nums.size() && nums[index] == nums[index - 1]){
            int len = temp.size();
            for(int i=0;i<len;i++){
                // cout<<i.size()<<" ";
                // &i.push_back(nums[index]);
                // cout<<i.size()<<endl;
                temp[i].push_back(nums[index]);
                ans.push_back(temp[i]);
            }
            // int x = temp.size();
            // cout<<index<<" "<<x<<endl;
            // for(int i=0;i<x;i++){
            //     auto p = temp[i];
            //     p.push_back(nums[index]);
            //     temp.push_back(p);
            // }
            index++;
            if(index >= nums.size()) break;
        }
        // ans.insert(ans.end(),temp.begin(),temp.end());
        // cout<<index<<endl;
        helper(nums,ans,index);
        // if(index == nums.size()){
        //     if(ans.size() == 0) ans.push_back(p);
        //     else if(ans.back() != p){
        //         ans.push_back(p);
        //     }
        //     return ;
        // }
        
        // helper(nums,ans,p,index+1);
        // p.push_back(nums[index]);
        // helper(nums,ans,p,index + 1);
        // p.pop_back();
        
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