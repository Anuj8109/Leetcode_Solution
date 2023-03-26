class Solution {
public:
    int helper(vector<int>& edges,vector<bool> &v,map<int,int> &m,int last,int index){
        if(m[index]){
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
            map<int,int> m;
            if(!v[i]){
                ans = max(ans,helper(edges,v,m,1,i));
            }
        }
        return ans == 0 ? -1 : ans;
    }
};