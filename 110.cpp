#include <iostream>
#include <cmath>
using namespace std;

/*
平衡二叉树

给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
*/

/*
思路：
    height递归
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
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        return max(height(root->left),height(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return abs(height(root->left)-height(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};

int main(){
    return 0;
}