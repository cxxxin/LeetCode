#include <iostream>
using namespace std;

/*
单值二叉树

如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
只有给定的树是单值二叉树时，才返回 true；否则返回 false。
*/

/*
思路：
    dfs
    和子树比
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
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        if(root->left && root->left->val!=root->val) return false;
        if(root->right && root->right->val!=root->val) return false;
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};

int main(){
    return 0;
}