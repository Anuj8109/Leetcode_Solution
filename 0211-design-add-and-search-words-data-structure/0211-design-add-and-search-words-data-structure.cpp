class word{
  public:
    vector<word*> v;
    bool is_leaf = false;
    word(){
        v.assign(26,NULL);
    }
    word *get(char c){
        return v[c - 'a'];
    }
    void add(char c){
        v[c - 'a'] = new word;
    }
    
};

class WordDictionary {
public:
    word* root;
    WordDictionary() {
        root = new word;
    }
     // WordDictionary() : root(new word) {}
    void addWord(string str) {
        // cout<<root<<endl;
        auto p = root;
        for(auto c:str){
            if(!p->get(c)) p->add(c);
            p = p->get(c);
        }
        p->is_leaf = true;
    }
    bool helper(string str,int i,word* root){
        if(i == str.size()) return root->is_leaf;
        
        if(str[i] != '.'){
            root = root->get(str[i]);
            // if(root->get(str[i])) return helper(str,i+1,root->get(str[i]));
            if(root) return helper(str,i+1,root);
            return false;
        }
        
        for(int j=0;j<26;j++){
            auto p = root->get('a' + j);
            if(p && helper(str,i+1,p)) return true;
            
        }
        return false;
    }
    bool search(string str) {
        return helper(str,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */