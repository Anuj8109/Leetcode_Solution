class Solution {
public:
    int count(vector<int> &edges,int start,int index){
        if(index == start) return 1;
        return 1 + count(edges,start,edges[index]);
    }
    int helper(vector<int>& edges,vector<bool> &v,unordered_set<int> &s,int index){
        if(s.find(index) != s.end()){
            return count(edges,index,edges[index]);
        }
        if(index == -1 || v[index]) return 0;
        
        
        
        s.insert(index);
        v[index] = 1;
        return helper(edges,v,s,edges[index]);
        
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        int ans = 0;
        
        vector<bool> v(n,false);
        for(int i=0;i<n;i++){
            int count = 0;
            unordered_set<int> s;
            if(!v[i]){
                ans = max(ans,helper(edges,v,s,i));
            }
        }
        return ans == 0 ? -1 : ans;
    }
};