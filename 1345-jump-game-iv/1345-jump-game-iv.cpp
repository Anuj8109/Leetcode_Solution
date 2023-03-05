class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> visit(n,0);
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            m[arr[i]].push_back(i);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        visit[0] = 1;
        unordered_set<int> us;
        while(!pq.empty()){
            auto p = pq.top();
            int steps = p.first;
            int index = p.second;
            visit[index] = 1;
            pq.pop();
            if(index == n - 1) return steps;
            if(index - 1 > 0 && !visit[index - 1]){
                if(index - 1 == n-1) return steps + 1;
                pq.push({steps + 1,index - 1});
            }
            if(index + 1 < n && !visit[index + 1]){
                if(index + 1 == n-1) return steps + 1;
                pq.push({steps + 1,index + 1});
            }
            if(us.find(arr[index]) == us.end()){
                us.insert(arr[index]);
                for(auto i:m[arr[index]]){
                    if(i == n - 1) return steps + 1;
                    if(!visit[i]) pq.push({steps + 1,i});
                }
            }
            
            
        }
        return n;
    }
};