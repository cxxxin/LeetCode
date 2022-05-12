#include <iostream>
using namespace std;

/*
二叉搜索树的最近公共祖先

给定一个[二叉搜索树], 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
*/

/*
思路：
    - 当其中两个数都大于/小于父节点的时候，就可以继续往下搜索
    - 当两个数一个大于父节点，一个小于父节点时，就可以停下了
    - 当其中一个就是父节点时，也可以停下了
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==root)
            return p;
        if(q==root)
            return q;

        int parent = root->val;
        if((p->val-parent)*(q->val-parent)<0) return root;
        if(p->val < parent) return lowestCommonAncestor(root->left,p,q);
        return lowestCommonAncestor(root->right,p,q);
    }
};

int main(){
    return 0;
}