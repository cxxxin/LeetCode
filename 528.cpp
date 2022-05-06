#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
using namespace std;

/*
按权重随机选择

给你一个 下标从 0 开始 的正整数数组 w ，其中 w[i] 代表第 i 个下标的权重。

请你实现一个函数 pickIndex ，它可以 随机地 从范围 [0, w.length - 1] 内（含 0 和 w.length - 1）选出并返回一个下标。
选取下标 i 的 概率 为 w[i] / sum(w) 。

例如，对于 w = [1, 3]，挑选下标 0 的概率为 1 / (1 + 3) = 0.25 （即，25%），
而选取下标 1 的概率为 3 / (1 + 3) = 0.75（即，75%）。
*/

/*
思路：
    轮盘赌
*/

class Solution {
private:
    vector<int> p;
    mt19937 gen; // <random> 是伪随机数产生器，用于产生高性能的随机数
    uniform_int_distribution<int> dis; // <random>，是一个随机数分布类，参数为生成随机数的类型，构造函数接受两个值表示区间段
    int N;

public:
    Solution(vector<int>& w) {
        int n = w.size();
        for (int i = 1; i < n; i++) w[i] += w[i - 1];
        p = move(w);
        N = p[n-1];
    }
    
    int pickIndex() {
        int r = dis(gen) % N + 1;
        return lower_bound(p.begin(),p.end(),r) - p.begin();
    }
};

class Solution1 {
public:
    vector<int> prefix; int m;
    Solution1(vector<int>& w) {
        srand((unsigned)time(NULL)); 
        for (int i = 1; i < w.size(); i++) w[i] += w[i - 1];
        prefix = move(w);
        m = prefix.back(); //总的权重为m，在[1, m]生成随机数，有m种可能
    }
    int pickIndex() {
         //如权重[1,3]，0对应的权重为1,1对应的权重为3，权重前缀和为[1,4],则在1-4产生随机数
         //随机数取到1是找到1，对应下标为0即为答案，取2,3,4找到4,下标为1即为答案
        cout<<*lower_bound(prefix.begin(), prefix.end(), rand() % m + 1);
        return distance(prefix.begin(), lower_bound(prefix.begin(), prefix.end(), rand() % m + 1));
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

int main(){
    vector<int> exp = {1,1,1,1,1,};
    Solution* s = new Solution(exp);
    int result = s->pickIndex();
    cout<<result<<endl;
    system("pause");
    return 0;
}