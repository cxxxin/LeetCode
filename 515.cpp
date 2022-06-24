#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/*
在每个树行中找最大值
给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
*/

/*
思路：
    广搜
    其实深搜也可以
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

// bfs
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root){
            return {};
        }

        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int len = que.size();
            int maxVal = INT32_MIN;
            for(int i=0;i<len;i++){
                TreeNode* curr = que.front();
                que.pop();
                maxVal = max(maxVal,curr->val);
                if(curr->left)
                    que.push(curr->left);
                if(curr->right)
                    que.push(curr->right);
            }
            ans.push_back(maxVal);
        }
        return ans;
    }
};

// dfs
class Solution {
private:
    vector<int> ans;
public:
    void dfs(TreeNode* root, int currHeight){
        if(currHeight == ans.size()){ // 新的一层
            ans.push_back(root->val);
        }
        else{
            ans[currHeight] = max(ans[currHeight],root->val);
        }
        if(root->left)
            dfs(root->left, currHeight+1);
        if(root->right)
            dfs(root->right, currHeight+1);
    }

    vector<int> largestValues(TreeNode* root) {
        if(!root){
            return {};
        }
        dfs(root,0);
        return ans;
    }
};

int main(){
    return 0;
}