#include <iostream>
#include <vector>
using namespace std;

/*
 二叉树的所有路径

 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
*/

/*
思路：
    dfs
    遇到有分支节点就复制多一份前面的路径，然后递归
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root->left && !root->right){
            return {to_string(root->val)};
        }

        int m=0, n=0; // 表示左右子树的路径数
        vector<string> childPathL, childPathR;
        if(root->left){
            childPathL = binaryTreePaths(root->left);
            m = childPathL.size();
        }
        if(root->right){
            childPathR = binaryTreePaths(root->right);
            n = childPathR.size();
        }
        // 遍历子树的vector
        vector<string> ans;
        ans.reserve(m+n);
        string pre = to_string(root->val) + "->";
        for(int i = 0;i<m;i++){
            ans.emplace_back(to_string(root->val) + "->");
            ans[i].append(childPathL[i]);
        }
        for(int i = 0;i<n;i++){
            ans.emplace_back(to_string(root->val) + "->");
            ans[i+m].append(childPathR[i]);
        }
        return ans;
    }
};

int main(){
    return 0;
}
