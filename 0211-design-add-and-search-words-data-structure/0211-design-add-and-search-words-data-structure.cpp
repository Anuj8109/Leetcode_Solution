class word{
  public:
    vector<word*> v;
    bool is_leaf = false;
    word(){
        v.assign(26,NULL);
    }
    
};

class WordDictionary {
public:
    word* root;
    WordDictionary() {
        root = new word;
    }
    void addWord(string str) {
        auto p = root;
        for(auto c:str){
            if(!p->v[c - 'a']) p->v[c - 'a'] = new word();
            p = p->v[c-'a'];
        }
        p->is_leaf = true;
    }
    bool helper(string str,int i,word* root){
        if(i == str.size()) return root->is_leaf;
        if(str[i] == '.'){
            for(int j=0;j<26;j++){
                auto p = root->v[j];
                if(p && helper(str,i+1,p)) return true;
            }
            return false;
        }
        root = root->v[str[i] - 'a'];
        if(!root) return false;
        return helper(str,i+1,root);
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