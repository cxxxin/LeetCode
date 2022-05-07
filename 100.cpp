#include <iostream>
using namespace std;

/*
相同的树

给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if(!p&&!q){
           return true;
       } 
       if(!p&&q || p&&!q){
           return false;
       }
       if(p->val!=q->val){
           return false;
       }
       return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

int main(){
    return 0;
}