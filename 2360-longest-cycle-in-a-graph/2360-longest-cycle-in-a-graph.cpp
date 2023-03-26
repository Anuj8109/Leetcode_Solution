class Solution {
public:
    int count(vector<int> &edges,int start,int index){
        if(index == start) return 1;
        return 1 + count(edges,start,edges[index]);
    }
    int helper(vector<int>& edges,vector<bool> &v,unordered_map<int,int> &m,int last,int index){
        if(m.count(index)){
            return last - m[index];
        }
        if(index == -1 || v[index]) return 0;
        m[index] = last++;
        v[index] = 1;
        return helper(edges,v,m,last,edges[index]);
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        int ans = 0;
        
        vector<bool> v(n,false);
        for(int i=0;i<n;i++){
            int count = 0;
            unordered_map<int,int> m;
            if(!v[i]){
                ans = max(ans,helper(edges,v,m,0,i));
            }
        }
        return ans == 0 ? -1 : ans;
    }
};