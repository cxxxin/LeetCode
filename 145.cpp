#include <iostream>
#include <vector>
using namespace std;

/*
二叉树的后序遍历
*/

/*
思路：
    后序遍历即先左子树、再右子树、最后到自己
    - 递归left
    - 递归right
    - print self->val
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
        dfs(root->left);
        dfs(root->right);
        ans.emplace_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        ans.reserve(100);
        dfs(root);
        return ans;
    }
};

int main(){
    return 0;
}