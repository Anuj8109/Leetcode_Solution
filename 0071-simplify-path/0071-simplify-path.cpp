class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int i = 1;
        int n = path.size();
        string curr = "";
        while(i < n){
            if(path[i] == '/'){
                if(curr == "" || curr == ".") 0;
                else if(curr == ".."){
                    if(!s.empty()) s.pop();
                }else{
                    s.push(curr);
                }
                curr = "";
                // cout<<s.size()<<" "<<i<<endl;
            }else{
                curr += path[i];
            }
            i++;
        }
        if(curr == "" || curr == ".") 0;
        else if(curr == ".."){
            if(!s.empty()) s.pop();
        }else{
            s.push(curr);
        }
        if(s.empty()) return "/";
        path = "";
        while(!s.empty()){
            path = "/" + s.top() + path;
            s.pop();
        }
        return path;
    }
};