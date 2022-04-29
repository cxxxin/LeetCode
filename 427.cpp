#include <iostream>
#include <vector>
#include <functional>
using namespace std;

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

/*
建立四叉树
*/

/*
思路：
    递归
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        function<Node*(int, int, int, int)> dfs = [&](int r0, int c0, int r1, int c1){
            for(int i=r0;i<r1;i++){
                for(int j=c0,j<c1;j++){
                    if(grid[i][j]!=grid[r0][c0]){ // not a leaf

                    }
                }
            }
            return new Node(grid[r0][c0],true); // a leaf
        }

        return dfs(0,0,grid.size(),grid.size());
    }
};

int main(){
    return 0;
}