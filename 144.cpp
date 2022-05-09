#include <iostream>
#include <vector>
using namespace std;

/*
二叉树的前序遍历

给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
*/

/*
思路：
    谦虚遍历其实就是先访问中间节点，再左儿子，再右儿子
    总的来说就是
    - visit curr
    - 递归 leftTree
    - 递归 rightTree
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
    vector<int> ans;
    void dfs(TreeNode* root){
        if(!root) return;
        ans.emplace_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        ans.reserve(100);
        dfs(root);
        return ans;
    }
};

int main(){
    return 0;
}