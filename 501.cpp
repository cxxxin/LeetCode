#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

/*
二叉搜索树中的众数

给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。

如果树中有不止一个众数，可以按 任意顺序 返回。

假定 BST 满足如下定义：

结点左子树中所含节点的值 小于等于 当前节点的值
结点右子树中所含节点的值 大于等于 当前节点的值
左子树和右子树都是二叉搜索树
*/

/*
思路：
    dfs遍历所有元素，同时用一个map记录每个元素出现的次数
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
    unordered_map<int,int> mp; // <val,count>
    void dfs(TreeNode* root){
        if(!root) return;
        mp[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        vector<int> ans;
        multimap<int,int,greater<int>> countMap;
        for(unordered_map<int,int>::iterator it = mp.begin();it!=mp.end();it++){
            countMap.insert({it->second,it->first});
        }
        int maxVal = countMap.begin()->first;
        for(multimap<int,int>::iterator it = countMap.begin();it!=countMap.end();it++){
            if(it->first!=maxVal) break;
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

int main(){
    return 0;
}