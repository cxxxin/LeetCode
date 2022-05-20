#include <iostream>
#include <cmath>
using namespace std;

/*
二叉树的坡度

给你一个二叉树的根节点 root ，计算并返回 整个树 的坡度 。

一个树的 节点的坡度 定义即为，该节点左子树的节点之和和右子树节点之和的 差的绝对值 。
如果没有左子树的话，左子树的节点之和为 0 ；没有右子树的话也是一样。空结点的坡度是 0 。

整个树 的坡度就是其所有节点的坡度之和。
*/

/*
思路：
    dfs
    对于每个节点来说，都是要returnroot的坡度+左子树的podu+右子树的坡度
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
    int getSum(TreeNode* root){
        if(!root) return 0;
        return root->val + getSum(root->left) + getSum(root->right);
    }
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        return abs(getSum(root->left)-getSum(root->right)) + findTilt(root->left) + findTilt(root->right);
    }
};

int main(){
    return 0;
}