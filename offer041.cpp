#include <iostream>
#include <vector>
using namespace std;

/*
剑指 Offer II 041. 滑动窗口的平均值

给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算滑动窗口里所有数字的平均值。

实现 MovingAverage 类：

MovingAverage(int size) 用窗口大小 size 初始化对象。
double next(int val) 成员函数 next 每次调用的时候都会往滑动窗口增加一个整数，
请计算并返回数据流中最后 size 个值的移动平均值，即滑动窗口里所有数字的平均值。
*/

/*
思路：
    用vector记录
    指针移动

    用队列更快
*/

class MovingAverage {
private:
    int size = 0;
    vector<int> arr;
    double sum = 0;
    int head = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        arr.reserve(size);
    }
    
    double next(int val) {
        sum += val;
        if(arr.size()<size){
            arr.push_back(val);
            return sum/arr.size();
        }
        else{
            sum -= arr[head];
            arr[head] = val;
            head++;
            head %= size;
            return sum/size;
        }
    }
};

int main(){
    return 0;
}