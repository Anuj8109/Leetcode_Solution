class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // vector<int> v(1e5 + 1,0);
        unordered_set<int> us;
        unordered_map<int,int> m;
        for(auto i:matches){
            us.insert(i[0]);
            us.insert(i[1]);
            m[i[1]]++;
        }
        
        vector<int> a;
        vector<int> b;
        for(auto i=us.begin();i!=us.end();i++){
            if(m[*i] == 0) a.push_back(*i);
            else if(m[*i] == 1) b.push_back(*i);
        }
        // for(int i=1;i<=1e5;i++){
        //     if(us.find(i) != us.end()){
        //         if(v[i] == 0) a.push_back(i);
        //         else if(v[i] == 1) b.push_back(i); 
        //     }
        // }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return {a,b};
    }
};