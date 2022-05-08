#include <iostream>
using namespace std;

/*
统计值等于子树平均值的节点数

给你一棵二叉树的根节点 root ，找出并返回满足要求的节点数，要求节点的值等于其 子树 中值的 平均值 。
注意：
n 个元素的平均值可以由 n 个元素 求和 然后再除以 n ，并 向下舍入 到最近的整数。
root 的 子树 由 root 和它的所有后代组成。
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
    int countNode(TreeNode* root){ // 计算节点数
        if(!root) return 0;
        return countNode(root->left)+countNode(root->right)+1;
    }

    int sumNode(TreeNode* root){ // 计算子树之和
        if(!root) return 0;
        return sumNode(root->left)+sumNode(root->right)+root->val;
    }

    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        return averageOfSubtree(root->left) + averageOfSubtree(root->right) + (int)(root->val==sumNode(root)/countNode(root));
    }
};

int main(){
    return 0;
}