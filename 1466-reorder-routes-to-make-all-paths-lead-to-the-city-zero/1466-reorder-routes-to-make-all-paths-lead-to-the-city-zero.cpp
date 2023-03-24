class Solution {
public:

    //
    // int ans = 0;
    // void helper(vector<vector<int>>& v,int n,int ind){
    //     // if(v[i].size() == 0 || visit[i]) return;
    //     // ans += v[i].size() - 1;
    //     // if(i == 0) ans++;
    //     // visit[i] = true;
    //     // cout<<v[i].size()<<" "<<i<<endl;
    //     for(auto j:v[ind]){
    //         helper(v,n,j);
    //         ans++;
    //         if(!visit[v[i][j]]){
    //             // cout<<j<<endl;
    //             helper(v,n,v[i][j]);
    //             ans++;
    //         }
    //     }
    // }
    void helper(vector<vector<int>> &v1,vector<vector<int>> &v2,vector<bool> &visit,int &ans,int index){
        if(visit[index]) return ;
        visit[index] = 1;
        for(auto i:v2[index]){
            if(!visit[i]) helper(v1,v2,visit,ans,i);
        }
        for(auto i:v1[index]){
            if(!visit[i]){
                ans++;
                helper(v1,v2,visit,ans,i);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& conn) {
        vector<vector<int>> v1(n);
        vector<vector<int>> v2(n);
        vector<bool> visit(n,false);
        for(auto i:conn){
            v1[i[0]].push_back(i[1]);
            v2[i[1]].push_back(i[0]);
        }
        int ans = 0;
        helper(v1,v2,visit,ans,0);
        // for(int i=0;i<n;i++){
        //     if(v[i].size() > 0){
        //         cout<<v[i].size()<<endl;
        //         // ans += v[i].size() - 1;
        //         // if(i == 0) ans++;
        //         helper(v,n,i);
        //     }
        // }
        return ans;
    }
};