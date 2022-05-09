#include <iostream>
#include <vector>
using namespace std;

/*
检查是否有合法括号字符串路径

一个括号字符串是一个 非空 且只包含 '(' 和 ')' 的字符串。如果下面[任意]条件为 真 ，那么这个括号字符串就是 合法的 。

字符串是 () 。
字符串可以表示为 AB（A 连接 B），A 和 B 都是合法括号序列。
字符串可以表示为 (A) ，其中 A 是合法括号序列。
给你一个 m x n 的括号网格图矩阵 grid 。网格图中一个 合法括号路径 是满足以下所有条件的一条路径：

路径开始于左上角格子 (0, 0) 。
路径结束于右下角格子 (m - 1, n - 1) 。
路径每次只会向 下 或者向 右 移动。
路径经过的格子组成的括号字符串是 合法 的。
如果网格图中存在一条 合法括号路径 ，请返回 true ，否则返回 false 
*/

/*
DFS+记忆
*/

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        
    }
};

int main(){
    return 0;
}