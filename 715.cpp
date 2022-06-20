#include <iostream>
#include <map>
using namespace std;

/*
Range 模块

Range模块是跟踪数字范围的模块。设计一个数据结构来跟踪表示为 半开区间 的范围并查询它们。
半开区间 [left, right) 表示所有 left <= x < right 的实数 x 。
*/

/*
思路：
    线段树
*/

class RangeModule {
public:
    RangeModule() {}
    
    void addRange(int left, int right) {
        auto it = intervals.upper_bound(left); // 找出最后一个满足l<left的区间[l,r)
        if (it != intervals.begin()) {
            auto start = prev(it);
            if (start->second >= right) { // [left,right) 已经被覆盖了，则不需要任何操作
                return;
            }
            if (start->second >= left) { // [left,right) 与[l,r)有一部分是重叠的，但left在[l,r)上，right在区间之外，在右边
                left = start->first; // 把left变成l，即新的区间是[l,right)
                intervals.erase(start); // 删除区间[l,r)
            }
        }
        while (it != intervals.end() && it->first <= right) { // 遍历[l,r)之后的区间，这些区间都满足l>left，只要满足l<right，就可以发生区间合并
            right = max(right, it->second);
            it = intervals.erase(it);
        }
        intervals[left] = right; // addRange
    }
    
    bool queryRange(int left, int right) { // 查找是否有一个区间可以完全覆盖left-right
        auto it = intervals.upper_bound(left);
        if (it == intervals.begin()) {
            return false;
        }
        it = prev(it);
        return right <= it->second;
    }
    
    void removeRange(int left, int right) {
        auto it = intervals.upper_bound(left); // 找出最后一个满足l<left的区间[l,r)
        if (it != intervals.begin()) {
            auto start = prev(it);
            if (start->second >= right) {
                int ri = start->second;
                if (start->first == left) {
                    intervals.erase(start);
                }
                else {
                    start->second = left;
                }
                if (right != ri) {
                    intervals[right] = ri;
                }
                return;
            }
            else if (start->second > left) {
                start->second = left;
            }
        }
        while (it != intervals.end() && it->first < right) {
            if (it->second <= right) {
                it = intervals.erase(it);
            }
            else {
                intervals[right] = it->second;
                intervals.erase(it);
                break;
            }
        }
    }

private:
    map<int, int> intervals;
};

int main(){
    return 0;
}