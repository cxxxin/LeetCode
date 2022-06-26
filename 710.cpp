#include <iostream>
#include <vector>
#include <random>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
黑名单中的随机数

给定一个整数 n 和一个 无重复 黑名单整数数组 blacklist 。
设计一种算法，从 [0, n - 1] 范围内的任意整数中选取一个 未加入 黑名单 blacklist 的整数。
任何在上述范围内且不在黑名单 blacklist 中的整数都应该有 同等的可能性 被返回。

优化你的算法，使它最小化调用语言 内置 随机函数的次数。
*/

/*
思路：
    只记录白名单
*/

// 时间超限

// 建立白名单的时候用线段表示连续区间而不是每个点都记
class Solution {
public:
    vector<pair<int,int>> canPick; // range
    vector<int> preSum; // 存放区间长度的前缀和，之所以用前缀和是因为要做轮盘赌

    Solution(int n, vector<int>& blacklist) {
        sort(blacklist.begin(), blacklist.end());
        int st = 0; // 新区间的左端点
        preSum.push_back(0);
        for(int black:blacklist){ // 区间的左端点在黑名单中
            if(st == black){
                st++;
                continue;
            }

            canPick.push_back({st, black-1});
            preSum.push_back(preSum.back()+black-st);
            st = black+1;
        }

        // 最后一个区间
        if(st!=n){
            canPick.push_back({st,n-1});
            preSum.push_back(preSum.back()+n-st);
        }
    }
    
    int pick() {
        int N = preSum.back();
        int t = rand()%N+1; // 从1开始
        int x = lower_bound(preSum.begin(),preSum.end(),t)-preSum.begin();

        auto iter = canPick[x-1];
        int n = iter.second - iter.first + 1; // length of the range
        return iter.first + rand()%n;
    }
};

class Solution1 {
public:
    int len;
    vector<int> canPick;
    Solution1(int n, vector<int>& blacklist) {
        unordered_set<int> blacks;
        for(int black:blacklist){
            blacks.emplace(black);
        }
        len = n-blacklist.size();
        canPick.reserve(len);
        for(int i=0;i<n;i++){
            if(!blacks.count(i)){
                canPick.push_back(i);
            }
        }
    }
    
    int pick() {
        int x = rand()%len;
        return canPick[x];
    }
};

int main(){
    return 0;
}