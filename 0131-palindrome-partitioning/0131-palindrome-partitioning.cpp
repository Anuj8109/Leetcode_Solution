class Solution {
public:
    unordered_set<string> us;
    bool pali(string& s){
        if(us.find(s) != us.end()) return 1;
        int i = 0;
        int j = s.size() - 1;
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        us.insert(s);
        return true;
            
    }
    
    vector<vector<string>> ans;
    void part(string& s,int i,vector<string>& p){
        if(i == s.size()){
            ans.push_back(p);
            // cout<<p.size()<<endl;
            return ;
        }
        string a;
        for(int j=1;j<=s.size() - i;j++){
            a = s.substr(i,j);
            if(us.find(a) != us.end() || pali(a)){
                p.push_back(a);
                part(s,i+j,p);
                p.pop_back();
            }
        }
        // return;
    }
    vector<vector<string>> partition(string s){
        vector<string> p={};
        part(s,0,p);
        return ans;
        
    }
};