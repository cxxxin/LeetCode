#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
637. 二叉树的层平均值

给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10-5 以内的答案可以被接受。
*/

/*
思路：
    bfs(层次遍历)
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        vector<double> ans;
        que.push(root);
        while(!que.empty()){
            double sum = 0;
            int size = que.size();
            for(int i=0;i<size;i++){
                TreeNode* node = que.front();
                que.pop();
                sum += node->val;
                if(node->left!=nullptr)
                    que.push(node->left);
                if(node->right!=nullptr)
                    que.push(node->right);
            }
            sum /= size;
            ans.push_back(sum);
        }
        return ans;
    }
};

int main(){
    return 0;
}