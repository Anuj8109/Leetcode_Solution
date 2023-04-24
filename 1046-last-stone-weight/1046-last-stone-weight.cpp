class Solution {
public:
    int lastStoneWeight(vector<int>& v) {
        priority_queue<int> pq(v.begin(),v.end());
        
        while(pq.size() > 1){
            int p = pq.top();
            pq.pop();
            int q = pq.top();
            pq.pop();
            if(p != q) pq.push(p - q);
        }
        return pq.empty() ? 0 : pq.top();
    }
};