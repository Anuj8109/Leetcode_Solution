class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
    // int maxk = INT_MIN;
    // bool com = true;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto i:nums) pq.push(i);
        while(pq.size() > k) pq.pop();
        
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */