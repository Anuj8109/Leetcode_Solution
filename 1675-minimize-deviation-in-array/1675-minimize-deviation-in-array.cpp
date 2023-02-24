class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(auto i:nums){
            if(i & 1) i= i*2;
            pq.push(i);
            mini = min(mini,i);
            maxi = max(maxi,i);
        }
        
        int mdiff = maxi - mini;
        // cout<<mdiff<<endl;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            mdiff = min(mdiff,x - mini);
            if(x & 1) break;
            pq.push(x/2);
            mini = min(mini,x/2);
            // cout<<mdiff<<endl;
        }
        return mdiff;
    }
};