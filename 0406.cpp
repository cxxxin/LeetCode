#include <iostream>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
面试题 04.06. 后继者

设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。
如果指定节点没有对应的“下一个”节点，则返回null。
*/

/*
思路：
    中序遍历
    中序遍历可以用dfs实现，从root的左子树开始，但每当发现指向p节点时，记录下来，然后找下一个节点
*/

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> st;
        TreeNode* prev = nullptr;
        TreeNode* curr = root;

        while(!st.empty() || curr!=nullptr){
            while(curr!=nullptr){ // 左子树
                st.emplace(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            if(prev == p) return curr; // 与中序遍历相比增加了这句

            prev = curr;
            curr = curr->right;
        }

        return nullptr;
    }
};

int main(){
    return 0;
}