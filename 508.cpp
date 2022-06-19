#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
出现次数最多的子树元素和

给你一个二叉树的根结点 root ，请返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，
返回所有出现次数最多的子树元素和（不限顺序）。
一个结点的 「子树元素和」 定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
*/

/*
思路：
    dfs+map
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool cmp_value(const pair<int, int> left,const pair<int,int> right)
{
	return left.second < right.second;
}

class Solution {
private:
    unordered_map<int,int> mp; // sum:count
public:
    int getSum(TreeNode* root){
        if(!root){
            return 0;
        }

        int sum = root->val+getSum(root->left)+getSum(root->right);
        mp[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int sum = getSum(root);
        vector<int> ans;
        int maxCnt = 0;
        for(auto iter:mp){
            if(iter.second>maxCnt){
                maxCnt = iter.second;
                ans.clear();
                ans.push_back(iter.first);
            }
            else if(iter.second==maxCnt){
                ans.push_back(iter.first);
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}