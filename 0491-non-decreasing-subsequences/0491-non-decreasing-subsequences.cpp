class Solution {
public:
    set<vector<int>> ans;
    void helper(vector<int> &p,vector<int> &nums,int curr){
        if(curr == nums.size()){
            // cout<<p.size()<<endl;
            if(p.size() > 1) ans.insert(p);
            return ;
        }
        // if(p.back() != nums[curr]){
            // cout<<p.back()<<endl;
            helper(p,nums,curr + 1);
        // }
        // else if(p.size() >  1){
        //     ans.push_back(p);
        // }
        if(p.back() > nums[curr]) return;
        p.push_back(nums[curr]);
        helper(p,nums,curr + 1);
        // for(int i=curr + 1;i<nums.size();i++){
        //     p.push_back(nums[i]);
        //     helper(p,nums,i + 1);
        //     p.pop_back();
        // }
        p.pop_back();
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> p;
        unordered_set<int> us;
        for(int i=0;i<nums.size();i++){
            if(us.find(nums[i]) != us.end()) continue;
            us.insert(nums[i]);
            p.push_back(nums[i]);
            helper(p,nums,i+1);
            p.pop_back();
        }
        return vector(ans.begin(),ans.end());
    }
};