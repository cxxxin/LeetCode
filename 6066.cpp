#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
统计区间中的整数数目
*/

/*
思路：
    难点在于用什么数据结构去记录有可能重叠的区间
    猜测和线段树有关
*/

class CountIntervals {
    CountIntervals *left = nullptr, *right = nullptr;
    int l, r, sum = 0;

public:
    CountIntervals() : l(1), r(1e9) {}

    CountIntervals(int l, int r) : l(l), r(r) {}

    void add(int L, int R) { // 为方便区分变量名，将递归中始终不变的入参改为大写（视作常量）
        if (sum == r - l + 1) return; // 当前节点已被完整覆盖，无需执行任何操作
        if (L <= l && r <= R) { // 当前节点已被区间 [L,R] 完整覆盖，不再继续递归
            sum = r - l + 1;
            return;
        }
        int mid = (l + r) / 2;
        if (left == nullptr) left = new CountIntervals(l, mid); // 动态开点
        if (right == nullptr) right = new CountIntervals(mid + 1, r); // 动态开点
        if (L <= mid) left->add(L, R);
        if (mid < R) right->add(L, R);
        sum = left->sum + right->sum;
    }

    int count() { return sum; }
};


// https://leetcode.cn/problems/count-integers-in-intervals/solution/by-endlesscheng-clk2/


int main(){
    return 0;
}