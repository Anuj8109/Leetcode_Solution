class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> us;
        string temp;
        int x;
        for(int i=0;i<nums.size();i++){
            us.insert(nums[i]);
            temp = to_string(nums[i]);
            reverse(temp.begin(),temp.end());
            // cout<<temp<<endl;
            x =  stoi(temp);
            us.insert(x);
        }
        return us.size();
    }
};