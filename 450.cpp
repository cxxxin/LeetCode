#include <iostream>
using namespace std;

/*
删除二叉搜索树中的节点
*/

/*
思路：
    分类讨论
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) { // root为空
            return nullptr;
        }
        if (root->val > key) { // key在右子树
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (root->val < key) { // key在左子树
            root->right = deleteNode(root->right, key);
            return root;
        }
        if (root->val == key) { // 就删当前的父节点
            if (!root->left && !root->right) { // 没有牵挂的节点，直接删了
                return nullptr;
            }
            if (!root->right) { // 只有一边的子树，所以直接上位即可
                return root->left;
            }
            if (!root->left) {
                return root->right;
            }
            TreeNode *successor = root->right; // 重构子树
            while (successor->left) { // 找到右子树中最后一个左儿子，即右子树中最小的数
                successor = successor->left;
            }
            root->right = deleteNode(root->right, successor->val); // 删除右子树最小的节点
            successor->right = root->right; // 把右子树最小的节点作为新的树根
            successor->left = root->left;
            return successor;
        }
        return root;
    }
};


int main(){
    return 0;
}