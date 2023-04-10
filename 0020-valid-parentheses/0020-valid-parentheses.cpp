class Solution {
public:
    bool isValid(string s) {
        if(s.size() & 1) return false;
        stack<char> q;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') q.push(s[i]);
            else{
                if(q.empty()) return false;
                char x = q.top();
                q.pop();
                // cout<<'(' - ')'<<endl;
                if(x == '(' && s[i] == ')') continue;
                else if(x == '{' && s[i] == '}') continue;
                else if(x == '[' && s[i] == ']') continue;
                else return false;
            }
            // cout<<s[i]<<endl;
        }
        if(q.empty()) return true;
        return false;
    }
};