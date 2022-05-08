#include <iostream>
using namespace std;

/*
二叉树的最小深度

给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明：叶子节点是指没有子节点的节点。
*/

/*
思路：
    BFS/DFS
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

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int leftHeight = minDepth(root->left);
        int rightHeight = minDepth(root->right);
        if(!leftHeight) return rightHeight+1;
        else if(!rightHeight) return leftHeight+1;
        else return min(leftHeight,rightHeight)+1;
    }
};

int main(){
    return 0;
}