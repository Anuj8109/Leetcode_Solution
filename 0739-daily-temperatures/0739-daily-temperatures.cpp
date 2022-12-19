class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> s;
        vector<int> ans(temp.size(),0);
        for(int i=temp.size() - 1;i >= 0;i--){
            while(!s.empty() && temp[s.top()] <= temp[i]){
                s.pop();
            }
            if(!s.empty()) ans[i] = s.top() - i;
            // else 
            s.push(i);
        }
        return ans;
        
    }
};