/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<Node*> visit;
    Solution(){
        visit.assign(101,NULL);
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        // cout<<node->val<<endl;
        Node* head = new Node(node->val);
        visit[node->val] = head;
        for(auto i:node->neighbors){
            if(!visit[i->val]){
                cloneGraph(i);
            }
            // Node* temp = cloneGraph(i);
            head->neighbors.push_back(visit[i->val]);
        }
        
        return head;
    }
};