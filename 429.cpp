#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
N叉树的层序遍历
*/

/*
思路：
    广度优先遍历
*/

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) { // 空树
            return {};
        }

        vector<vector<int>> ans;
        queue<Node*> q;
        q.emplace(root);
        while (!q.empty())
        {
            // 记录当前的层级的所有节点
            vector<int> level;
            int count = q.size(); // 当前这层有多少元素
            for (int i = 0; i < count; i++)
            {
                Node* curr = q.front(); // 取出当前层级的节点
                q.pop();
                level.push_back(curr->val);
                // 把所有子节点放进队列
                for (Node* child : curr->children)
                {
                    q.emplace(child);
                } 
            }
            ans.push_back(move(level)); //move()函数：将左值强制转换为右值
        }

        return ans;
    }
};


int main(){
    return 0;
}