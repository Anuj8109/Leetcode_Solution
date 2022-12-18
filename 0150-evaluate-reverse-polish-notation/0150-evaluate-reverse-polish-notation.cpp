class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> s;
        for(auto p:tokens){
            if(p == "+" || p == "-" || p == "*" || p == "/"){
                long a = s.top();
                s.pop();
                long b = s.top();
                s.pop();
                if(p == "+") s.push(a + b);
                else if(p == "-") s.push(b  - a);
                else if(p == "*") s.push(a * b);
                else s.push(b / a);
            }else{
                int a = stol(p);
                s.push(a);
            }
            // cout<<s.top()<<endl;
        }
        return s.top();
    }
};