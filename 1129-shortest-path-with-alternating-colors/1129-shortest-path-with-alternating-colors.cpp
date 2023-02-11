class Solution {
public:
    vector<int> ans;
    vector<vector<int>> reds;
    vector<vector<int>> blues;
    vector<vector<bool>> rv;
    vector<vector<bool>> bv;
    void dfs(int start,int count,bool color,int last){ // color = true for red and false for blue
        // if(ans[start] != -1 && ans[start] < count) return ;
        if(color && rv[last][start] ) return;
        else rv[last][start] = true;
        if(!color && bv[last][start]) return ;
        else bv[last][start] = true;
        if(ans[start] == -1) ans[start] = count;
        else ans[start] = min(count,ans[start]);
        // visit[start][color] = true;
        cout<<start<<" "<<last<<" "<<count<<endl;
        if(color){
            for(auto i:reds[start]){
                if(rv[start][i] == false){
                    dfs(i,count + 1,!color,start); 
                    // rv[start][i] = true;
                }
            }
        }else{
            for(auto i:blues[start]){
                if(bv[start][i] == false){
                    dfs(i,count + 1,!color,start); 
                    // bv[start][i] = true;
                }
            }
                
        }
        
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        ans.assign(n,-1);
        reds.resize(n);
        blues.resize(n);
        // visit.assign(n,vector<bool> (2,false));
        rv.assign(n,vector<bool> (n,false));
        bv.assign(n,vector<bool> (n,false));
        for(auto i:redEdges){
            reds[i[0]].push_back(i[1]);
        }
        for(auto i:blueEdges){
            blues[i[0]].push_back(i[1]);
        }
        // dfs(0,0,1,0);
        // dfs(0,0,0,0);
        queue<vector<int>> q;
        q.push({0,0,1});
        q.push({0,0,0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            if(ans[p[0]] == -1) ans[p[0]] = p[1];
            else ans[p[0]] = min(ans[p[0]],p[1]);
            if(p[2] == 1){
                for(int i:reds[p[0]]){
                    if(rv[p[0]][i] == false) q.push({i,p[1] + 1,0}); rv[p[0]][i] = true;
                }
            }else{
                for(int i:blues[p[0]]){
                    if(bv[p[0]][i] == false) q.push({i,p[1] + 1,1}); bv[p[0]][i] = true;
                }
            }
        }
        return ans;
    }
};