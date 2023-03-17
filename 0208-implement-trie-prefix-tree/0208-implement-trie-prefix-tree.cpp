class TrieNode{
    public:
    vector<TrieNode*> v;
    bool end;
    TrieNode(){
        v.assign(26,NULL);
        end = false;
    }
    
    TrieNode* getNode(int a){
        // cout<<a<<endl;
        return v[a];
    }
    void setNode(int a){
        v[a] = new TrieNode();
    }
    
    bool getEnd(){
        return end;
    }
    void setEnd(){
        end = 1;
    }
};


class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto temp = root;
        for(auto i:word){
            if(temp->getNode(i - 'a') == NULL) temp->setNode(i-'a');
            temp = temp->getNode(i-'a');
        }
        temp->setEnd();
        
    }
    
    bool search(string word) {
        auto temp = root;
        for(auto i:word){
            if(temp->getNode(i - 'a') == NULL) return false;
            temp = temp->getNode(i - 'a');
        }
        return temp->getEnd();
    }
    
    bool startsWith(string prefix) {
        auto temp = root;
        for(auto i:prefix){
            if(temp->getNode(i - 'a') == NULL) return false;
            temp = temp->getNode(i - 'a');
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */