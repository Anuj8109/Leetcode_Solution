class StockSpanner {
public:
    // vector<int> v;
    stack<pair<int,int>> s;
    int count = 0;;
    StockSpanner() {
        // count = 0;
        // s.push(INT_MAX,0);
    }
    
    int next(int p) {
        // int n = v.size();
        // int i;
        // for(i=n-1;i>=0;i--){
        //     if(v[i] > p) break;
        // }
        // v.push_back(p);
        // return n - i;
        // int span = 1;
        // while(!s.empty() && s.top().first <= p){
        //     span += s.top().second;
        //     s.pop();
        // }
        // s.push({p,span});
        // return span;
        count++;
        while(!s.empty() && s.top().first <= p) s.pop();
        // if()
        int ans = count;
        if(!s.empty()) ans -= s.top().second;
        s.push({p,count});
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */