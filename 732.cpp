#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

/*
我的日程安排表 III

当 k 个日程安排有一些时间上的交叉时（例如 k 个日程安排都在同一时间内），就会产生 k 次预订。

给你一些日程安排 [start, end) ，请你在每个日程安排添加后，返回一个整数 k ，表示所有先前日程安排会产生的最大 k 次预订。

实现一个 MyCalendarThree 类来存放你的日程安排，你可以一直添加新的日程安排。

MyCalendarThree() 初始化对象。
int book(int start, int end) 返回一个整数 k ，表示日历中存在的 k 次预订的最大值。
*/

/*
思路：
    区间问题，线段树？
    差分数组也可以？
*/

class MyCalendarThree {
public:
    map<int, int> mp;
    MyCalendarThree() {

    }
    
    int book(int start, int end) {
        int ans = 0;
        int maxBook = 0;
        mp[start]++;
        mp[end]--;
        for(auto &[_, freq]:mp){
            maxBook += freq;
            ans = max(ans,maxBook);
        }
        return ans;
    }
};

class MyCalendarThree2 {
public:
    unordered_map<int, pair<int, int>> tree; 
    /*
    key记录树中每个节点的index，这个树是完全二叉树，每个节点必须有俩子节点，每个节点表示的都是一个区间，子节点表示的是子区间
    value->first记录的是该区间的最大重叠次数，value->second记录的是该区间被整个覆盖的次数
    */

    MyCalendarThree() {

    }
    
    void update(int start, int end, int l, int r, int idx) { // start是日程的开始时间，end是结束时间
        if (r < start || end < l) { // 该日程与当前区间完全无关
            return;
        } 
        if (start <= l && r <= end) { // 该日程完全覆盖了当前区间，则直接更新当前区间的节点，不用往下更新
            tree[idx].first++;
            tree[idx].second++;
        } else { // 该日程无法完全覆盖当前区间，但是又有重叠的部分
            int mid = (l + r) >> 1;
            update(start, end, l, mid, 2 * idx); // 划分子区间，更细地update
            update(start, end, mid + 1, r, 2 * idx + 1);
            tree[idx].first = tree[idx].second + max(tree[2 * idx].first, tree[2 * idx + 1].first); // 子区间互不重叠，取其最大值与second相加即可
        }
    }

    int book(int start, int end) {            
        update(start, end - 1, 0, 1e9, 1);
        return tree[1].first;
    }
};

int main(){
    return 0;
}
