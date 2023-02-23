class Solution {
public:
    static bool fun(pair<int,int> a,pair<int,int> b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> v;
        int n = profits.size();
        for(int i=0;i<n;i++){
            v.push_back({capital[i],profits[i]});
        }
        
        sort(v.begin(),v.end());
        priority_queue<int> pq;
        int index = 0;
        // cout<<v[0].first<<" "<<v[0].second<<endl;
        while(k > 0){
            while(index < n && v[index].first <= w){
                pq.push(v[index].second);
                index++;
            }
            if(pq.empty()) break;
            w += pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};