#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
最小高度树

给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。给定数字 n 和一个有 n - 1 条无向边的 edges 列表（每一个边都是一对标签），
其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条无向边。
可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为 h 。
在所有可能的树中，具有最小高度的树（即，min(h)）被称为 最小高度树 。

请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。
*/

/*
思路：
    树形动规
*/

class Solution {
public:
    // heightChild 表示子树高
    // heightRoot 表示树高

    // 计算q当前树的所有子树高度，curr表示当前的根节点
    void dfsForCurrentTree(vector<vector<int>>& graph, vector<int>& heightChild, int curr){
        heightChild[curr] = 1; // 初始化，如果没有子节点则树的高度是1
        int h = 0;
        for (int v:graph[curr]) // 找到其所有邻居节点，从邻居出发更新子树高度
        {
            if (heightChild[v]) // 已经更新过了
            {
                continue;
            }
            dfsForCurrentTree(graph,heightChild,v);
            h = max(h, heightChild[v]); // 子树中最高的高度
        }
        heightChild[curr] = h + 1; // 
    }

    // 进行换根动态规划，计算出所有的树高
    void dfsForAllTree(vector<vector<int>>& graph, vector<int>& heightChild, vector<int>& heightRoot, int curr){
        // 存储子树高度中的最大值和次大值
        int first = 0;
        int second = 0;
        for (int v:graph[curr]) // 遍历邻居节点
        {
            if (heightChild[v] > first)
            {
                second = first;
                first = heightChild[v];
            }
            else if (heightChild[v] > second)
            {
                second = heightChild[v];
            }     
        }
        heightRoot[curr] = first + 1;// 当前树的高度

        // 开始换根
        for (int v:graph[curr])
        {
            if (heightRoot[v]) // 已经更新过
            {
                continue;
            }
            // 换根到v
            heightChild[curr] = (heightChild[v] != first ? first : second) + 1; // 不更新v的高度是因为用不上，就到它的轮次再改吧
            // 往下搜
            dfsForAllTree(graph,heightChild,heightRoot,v);
        }
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n); // 邻接列表
        for (vector<int> e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        // 存储树的高度与子树的高度
        vector<int> heightRoot(n,0);
        vector<int> heightChild(n,0); // 只与当前的树有关

        // 从节点0开始先计算树的高度与子树的高度
        dfsForCurrentTree(graph, heightChild, 0);
        // 以0树为基准开始换根
        dfsForAllTree(graph, heightChild, heightRoot, 0);

        // 比较所有树高
        vector<int> ans;
        int h = n; // 树最高的一种可能
        for (int i = 0; i < n; i++)
        {
            if (heightRoot[i] < h)
            {
                h = heightRoot[i];
                ans.clear();
            }
            if (heightRoot[i] == h)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}