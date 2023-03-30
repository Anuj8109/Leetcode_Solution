class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty()) left.push(num);
        else if(left.top() >= num){
            // right.top()
            left.push(num);
            if(left.size() - 1 != right.size()){
                right.push(left.top());
                left.pop();
            }
        }else{
            right.push(num);
            if(left.size() < right.size()){
                left.push(right.top());
                right.pop();
            }
        }
        // cout<<left.size()<<" "<<right.size()<<endl;
    }
    
    double findMedian() {
        if(left.size() > right.size()) return left.top();
        return (left.top() + right.top())/2.00;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */