#include <iostream>
#include <queue>
using namespace std;

/*
找树左下角的值

给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
假设二叉树中至少有一个节点。
*/

/*
思路：
    层序遍历（先右再左） 队列实现
*/

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
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* curr;
        while(!que.empty()){
            curr = que.front();
            ans = curr->val;
            que.pop();
            if(curr->right){
                que.push(curr->right);
            }
            if(curr->left){
                que.push(curr->left);
            }
        }

        return ans;
    }
};

int main(){
    return 0;
}