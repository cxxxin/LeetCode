#include <iostream>
#include <queue>
using namespace std;

/*
另一棵树的子树
*/

/*
思路：
    递归验证
    先找到父节点的值相同的地方
    父节点值是否相同  && 左子树是否相同 && 右子树是否相同
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
    bool isSame(TreeNode* root1, TreeNode* root2){
        if((!root1)&&(!root2)) return true;
        if(!(root1 && root2)) return false;
        return root1->val == root2->val && isSame(root1->left,root2->left) && isSame(root1->right,root2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> que;
        que.emplace(root);
        TreeNode* curr;
        while(!que.empty()){
            curr = que.front();
            que.pop();
            if(isSame(curr,subRoot)) return true;
            if(curr->left){
                que.emplace(curr->left);
            }
            if(curr->right){
                que.emplace(curr->right);
            }
        }
        return false;
    }
};

int main(){
    return 0;
}