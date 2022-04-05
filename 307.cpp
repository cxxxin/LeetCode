#include <iostream>
#include <vector>

using namespace std;


/*
区域和检索--数组可修改

给你一个数组 nums ，请你完成两类查询。

其中一类查询要求 更新 数组 nums 下标对应的值
另一类查询要求返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 ，其中 left <= right
*/

/*
思路：
    线段树
*/

class NumArray {
private:
    vector<int> segmentTree;
    int n;

    // node-节点编号  s-区间的左边界在nums中的索引  e-区间的右边界
    void build(int node, int s, int e, vector<int> &nums) {
        if (s == e) { // 节点
            segmentTree[node] = nums[s];
            return;
        }
        int m = s + (e - s) / 2; // 父节点
        build(node * 2 + 1, s, m, nums); // 左边的子节点
        build(node * 2 + 2, m + 1, e, nums); // 右边的子节点
        segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2]; //所以segmentTree存的是和？
    }

    void change(int index, int val, int node, int s, int e) {
        if (s == e) { // 子节点
            segmentTree[node] = val;
            return;
        }
        int m = s + (e - s) / 2; // 一层层往下搜索
        if (index <= m) {
            change(index, val, node * 2 + 1, s, m);
        } else {
            change(index, val, node * 2 + 2, m + 1, e);
        }
        segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2];
    }

    int range(int left, int right, int node, int s, int e) {
        if (left == s && right == e) { // 刚好是节点存了的和，[left,right]是树上的某个子区间
            return segmentTree[node];
        }
        int m = s + (e - s) / 2;
        if (right <= m) {
            return range(left, right, node * 2 + 1, s, m);
        } else if (left > m) {
            return range(left, right, node * 2 + 2, m + 1, e);
        } else {
            return range(left, m, node * 2 + 1, s, m) + range(m + 1, right, node * 2 + 2, m + 1, e);
        }
    }

public:
    NumArray(vector<int>& nums) : n(nums.size()), segmentTree(nums.size() * 4) {
        build(0, 0, n - 1, nums);
    }

    void update(int index, int val) {
        change(index, val, 0, 0, n - 1);
    }

    int sumRange(int left, int right) {
        return range(left, right, 0, 0, n - 1);
    }
};

int main(){
    return 0;
}