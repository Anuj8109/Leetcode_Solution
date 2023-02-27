/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* helper(vector<vector<int>>& grid,int p,int q,int len){
        // int n = grid.size();
        bool f = 1;
        int val = grid[p][q];
        for(int i=p;i<p + len;i++){
            for(int j=q;j<q + len;j++){
                // cout<<i<<" "<<j<<endl;
                if(val != grid[i][j]){
                    f = 0;
                    break;
                }
            }
        }
        // cout<<f<<endl;
        if(f){
            return new Node(val,1);
        }
        Node* root = new Node(0,0);
        len = len/2;
        root->topLeft = helper(grid,p,q,len);
        root->topRight = helper(grid,p,q + len,len);
        root->bottomLeft = helper(grid,p+len,q,len);
        root->bottomRight = helper(grid,p+len,q+len,len);
        return root;
    }
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid,0,0,grid.size());
    }
};