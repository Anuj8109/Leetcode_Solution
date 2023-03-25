class Node{
public:  
    Node* parent;
    vector<Node*> v;
    char c;
    Node(char ch,Node* p){
        c = ch;
        parent = p;
    }
    void addChild(Node* p){
        v.push_back(p);
    }
};


class Solution {
public:
    int helper(Node* head,int &ans){
        if(!head) return 0;
        
        int current = 0;
        for(auto i:head->v){
            int temp = helper(i,ans);
            if(head->c != i->c){
                ans = max(ans,current + temp + 1);
                current = max(current,temp);
            }
        }
        current++;
        ans = max(ans,current);
        return current;
    }
    int longestPath(vector<int>& par, string s) {
        Node* head;
        map<int,Node*> m;
        // cout<<par.size()<<endl;
        for(int i=0;i<par.size();i++){
            m[i] = new Node(s[i],NULL);
        }
        for(int i=0;i<par.size();i++){
            if(par[i] == -1){
                head = m[i];
            }else{
                m[i]->parent = m[par[i]];
                m[par[i]]->addChild(m[i]);
            }
        }
        int ans = 0;
        auto temp = head;
        helper(temp,ans);
        return ans;
    }
};