// class Node{
// public:  
//     Node* parent;
//     vector<int> v;
//     char c;
//     Node(char ch,Node* p){
//         c = ch;
//         parent = p;
//     }
//     void addChild(int p){
//         v.push_back(p);
//     }
// };


class Solution {
public:
    // int helper(Node* head,unordered_map<int,Node*> &m,int &ans){
    //     if(!head) return 0;
    //     int current = 0;
    //     for(auto i:head->v){
    //         auto p = m[i];
    //         int temp = helper(p,m,ans);
    //         if(head->c != p->c){
    //             ans = max(ans,current + temp + 1);
    //             current = max(current,temp);
    //         }
    //     }
    //     current++;
    //     // ans = max(ans,current);
    //     return current;
    // }
    
    int helper(vector<vector<int>> &graph,string &s,int &ans,int index){
        int current = 0;
        for(auto i:graph[index]){
            int temp = helper(graph,s,ans,i);
            if(s[i] != s[index]){
                ans = max(ans,current + temp + 1);
                current = max(current,temp);
            }
        }
        // current++;
        return current + 1;
    }
    int longestPath(vector<int>& par, string s) {
        int n = par.size();
        vector<vector<int>> v(n);
        for(int i=1;i<n;i++){
            v[par[i]].push_back(i);
        }
        int ans = 0;
        return max(ans,helper(v,s,ans,0));
        // unordered_map<int,Node*> m;
        // // cout<<par.size()<<endl;
        // for(int i=0;i<par.size();i++){
        //     m[i] = new Node(s[i],NULL);
        // }
        // for(int i=0;i<par.size();i++){
        //     if(par[i] != -1){
        //         m[i]->parent = m[par[i]];
        //         m[par[i]]->addChild(i);
        //     }
        // }
        // int ans = 0;
        // Node* head = m[0];
        // ans = max(ans,helper(head,m,ans));
        // return ans;
    }
};