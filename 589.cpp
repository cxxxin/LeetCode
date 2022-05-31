#include <iostream>
#include <vector>
using namespace std;

/*
N 叉树的前序遍历
*/

/*
思路： 
    dfs
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> ans;
    void dfs(Node* root){
        if(!root) return;
        ans.push_back(root->val);
        for(Node* child:root->children){
            dfs(child);
        }
    }
    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }
};

int main(){
    return 0;
}