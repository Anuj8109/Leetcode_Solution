class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if(node1 == node2) return node1;
        int size = edges.size();
        vector<int> v1(size,-1);
        vector<int> v2(size,-1);
        v1[node1] = 0;
        v2[node2] = 0;
        int next = edges[node1];
        int last = 0;
        while(next != -1 && v1[next] == -1){
            v1[next] = last + 1;
            last++;
            next = edges[next];
        }
        next = edges[node2];
        last = 0;
        while(next != -1 && v2[next] == -1){
            v2[next] = last + 1;
            last++;
            next = edges[next];
        }
        int ans = size;
        int mdis = INT_MAX;
        for(int i=0;i<size;i++){
            // if(i == node1 || i == node2) continue;
            if(v1[i] != -1 && v2[i] != -1 && mdis >= max(v1[i],v2[i])){
                if(mdis == max(v1[i],v2[i])) ans = min(ans,i);
                else ans = i;
                mdis = max(v1[i],v2[i]);
                
            }
        }
        return ans == size ? -1 : ans;
    }
};