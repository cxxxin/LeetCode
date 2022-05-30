#include <iostream>
using namespace std;

/*
从根到叶的二进制数之和

给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。
例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。
对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。
返回这些数字之和。题目数据保证答案是一个 32 位 整数。
*/

/*
思路：
    dfs，设置一个全局变量ans记录总和
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
    int ans = 0;
    void dfs(TreeNode* root, int preSum){
        if((!root->left) && (!root->right)){ // leaf
            preSum = preSum << 1;
            preSum += root->val;
            ans += preSum;
            return;
        }
        preSum = preSum << 1;
        preSum += root->val;
        cout<<preSum<<endl;
        if(root->left)
            dfs(root->left, preSum);
        if(root->right)
            dfs(root->right, preSum);
    }
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};

int main(){
    return 0;
}