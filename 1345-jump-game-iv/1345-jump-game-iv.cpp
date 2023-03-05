class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size() == 1) return 0;
        int n = arr.size();
        vector<bool> visit(n,0);
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            m[arr[i]].push_back(i);
        }
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        queue<int> q;
        // pq.push({0,0});
        q.push(0);
        visit[0] = 1;
        unordered_set<int> us;
        int steps = 0;
        while(!q.empty()){
            int count = q.size();
            for(int i=0;i<count;i++){
                int index = q.front();
                q.pop();
                if(index - 1 > 0 && !visit[index - 1]){
                    if(index - 1 == n-1) return steps + 1;
                    q.push(index - 1);
                    visit[index - 1] = 1;
                }
                if(index + 1 < n && !visit[index + 1]){
                    if(index + 1 == n-1) return steps + 1;
                    q.push(index + 1);
                    visit[index + 1] = 1;
                }
                if(us.find(arr[index]) == us.end()){
                    us.insert(arr[index]);
                    for(auto i:m[arr[index]]){
                        if(i == n - 1) return steps + 1;
                        if(!visit[i]) q.push(i),visit[i] = 1;
        
                    }
                }
            }
            steps++;
        }
        return n;
    }
};