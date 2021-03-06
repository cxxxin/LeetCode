#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
N 叉树的最大深度

给定一个 N 叉树，找到其最大深度。
最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。
*/

/*
思路：
    dfs
*/

// Definition for a Node.
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
    int maxDepth(Node* root) {
        if(!root) return 0;
        if(root->children.empty()) return 1;

        int n = root->children.size();
        int height = 0;
        for(Node* child:root->children){
            height = max(height,maxDepth(child)+1);
        }
        return height;
    }
};

int main(){
    system("pause");
    return 0;
}