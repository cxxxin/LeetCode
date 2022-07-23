#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

/*
剑指 Offer II 115. 重建序列
*/

/*
思路：
    拓扑排序
    https://leetcode.cn/problems/ur2n8P/solution/zhong-jian-xu-lie-by-leetcode-solution-urxc/
*/

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size(); // 有n个节点
        vector<int> indegrees(n + 1); // 记录每个节点的入度
        vector<unordered_set<int>> graph(n + 1); // 建立有向图
        for (auto &sequence : sequences) {
            for (int i = 1; i < sequence.size(); i++) {
                int prev = sequence[i - 1], next = sequence[i];
                if (!graph[prev].count(next)) {
                    graph[prev].emplace(next); // 加一条边
                    indegrees[next]++; // 入度++
                }
            }
        }
        queue<int> qu; // 用来选择下一个节点
        for (int i = 1; i <= n; i++) {
            if (indegrees[i] == 0) { // 入度为0
                qu.emplace(i);
            }
        }
        while (!qu.empty()) {
            if (qu.size() > 1) { // 有不止一个选择
                return false;
            }
            int num = qu.front(); // 新的起点
            qu.pop();
            for (int next : graph[num]) { // 找下一个可去的节点
                indegrees[next]--; // 入度--
                if (indegrees[next] == 0) { // 入度为0就可以成为新的起点了
                    qu.emplace(next);
                }
            }
        }
        return true;
    }
};

int main(){
    return 0;
}