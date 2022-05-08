#include <iostream>
#include <stack>
using namespace std;

/*
对称二叉树

给你一个二叉树的根节点 root ， 检查它是否轴对称。
*/

/*
思路：
    分别dfs/bfs两边两棵子树（不同的方向）
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
    bool check(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true; // 两边的子树为空
        if (!p || !q) return false; // 仅有一边为空
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return check(root->left,root->right);
    }
};

int main(){
    return 0;
}