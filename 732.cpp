#include <iostream>
#include <vector>
#include <map>
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