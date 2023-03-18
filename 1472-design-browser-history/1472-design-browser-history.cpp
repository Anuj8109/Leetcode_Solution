class BrowserHistory {
public:
    vector<string> v;
    int index;
    int size;
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        index = 0;
        size = 1;
    }
    
    void visit(string url) {
        while(index + 1 < size){
            v.pop_back();
            size--;
        }
        v.push_back(url);
        index++;
        size++;
    }
    
    string back(int steps) {
        if(index < steps){
            index = 0;
            // return v[index];
        }else index = index - steps;
        return v[index];
    }
    
    string forward(int steps) {
        if(size - index - 1 < steps) index = size - 1;
        else index += steps;
        return v[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */