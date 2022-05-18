#include <iostream>
#include <stack>
using namespace std;

/*
二叉树的直径

给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。
这条路径可能穿过也可能不穿过根结点。
*/

/*
思路：
    路径长度：两段到公共祖先的距离之和
    如何找最长：dfs，对于每个root都找自己往左and往右的最长路径
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
    int maxLength(TreeNode* root){ // 计算树高
        if(!root) return 0;
        return max(maxLength(root->left),maxLength(root->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        stack<TreeNode*> st;
        int ans = 0;
        st.emplace(root);
        TreeNode* curr = root->left;
        while(!st.empty()||curr!=nullptr){
            while(curr!=nullptr){
                st.emplace(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            int currLen = 0;
            int leftLen = maxLength(curr->left)-1;
            int rightLen = maxLength(curr->right)-1;
            currLen += curr->left ? leftLen+1 : 0;
            currLen += curr->right ? rightLen+1: 0;
            ans = max(ans,currLen);
            curr = curr->right;
        }

        return ans;
    }
};

int main(){
    return 0;
}