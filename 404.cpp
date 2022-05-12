#include <iostream>
using namespace std;

/*
左叶子之和

给定二叉树的根节点 root ，返回所有左叶子之和。
*/

/*
思路：
    dfs
    - 没有左子树，return0
    - 有左子树，+left然后往下搜
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
    bool isLeafNode(TreeNode* node) {
        return !node->left && !node->right;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(!root){
            return 0;
        }

        int ans = 0;
        if(root->left){
            if(isLeafNode(root->left)){
                ans += root->left->val;
            }
            else{
                ans += sumOfLeftLeaves(root->left);
            }
        }
        if(root->right && !isLeafNode(root->right)){
            ans += sumOfLeftLeaves(root->right);
        }

        return ans;
    }
};

int main(){
    return 0;
}