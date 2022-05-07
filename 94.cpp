#include <iostream>
#include <vector>
using namespace std;

/*
二叉树的中序遍历

给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
*/


/*
思路：
    中序遍历其实就是先左子树，然后中间节点，然后右子树的顺序。
    所以递归地分为三个步骤：
    1. 先遍历左子树
    2. 加入中间节点
    3. 遍历右子树
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
        if(!root){ // 节点为空
            return;
        }

        dfs(root->left);    
        ans.emplace_back(root->val);
        dfs(root->right);
        return;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        ans.reserve(100);
        dfs(root);
        return ans;
    }
};

int main(){
    return 0;
}