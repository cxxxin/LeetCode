#include <iostream>
using namespace std;

/*
814. 二叉树剪枝

给你二叉树的根结点 root ，此外树的每个结点的值要么是 0 ，要么是 1 。
返回移除了所有不包含 1 的子树的原二叉树。
节点 node 的子树为 node 本身加上所有 node 的后代。
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

class Solution {
public:
    bool dfs(TreeNode* node){
        bool ans = node->val;
        if(node->left){
            if(!dfs(node->left)){
                node->left = nullptr;
            }
            else{
                ans = true;
            }
        }
        if(node->right){
            if(!dfs(node->right)){
                node->right = nullptr;
            }
            else{
                ans = true;
            }
        }

        return ans;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool ans = dfs(root);
        if(!ans && root->val==0) return nullptr;
        return root;
    }
};

int main(){
    return 0;
}