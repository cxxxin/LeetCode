#include <iostream>
#include <vector>
using namespace std;

/*
二叉搜索树的最小绝对差

给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
差值是一个正数，其数值等于两值之差的绝对值。
*/

/*
思路：
    首先，这是个二叉搜索树，所以一定是相邻的节点之间差值更小，不用考虑距离>1的节点了
    - 中序遍历得到有序序列
    - 找相邻差值
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
    vector<int> seq;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        seq.emplace_back(root->val);
        dfs(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        int ans = INT32_MAX;
        for(int i=1;i<seq.size();i++){
            int diff = seq[i] - seq[i-1];
            if(diff<ans)
                ans = diff;
        }
        return ans;
    }
};

int main(){
    return 0;
}