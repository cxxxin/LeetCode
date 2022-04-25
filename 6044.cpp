#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

/*
花期内花的数目

给你一个下标从 0 开始的二维整数数组 flowers ，其中 flowers[i] = [starti, endi] 表示第 i 朵花的 花期 从 starti 到 endi （都 包含）。同时给你一个下标从 0 开始大小为 n 的整数数组 persons ，persons[i] 是第 i 个人来看花的时间。

请你返回一个大小为 n 的整数数组 answer ，其中 answer[i]是第 i 个人到达时在花期内花的 数目.
*/

/*
思路：
    排序+遍历
*/
static bool cmp(const vector<int>& a, const vector<int>& b){
    return a[0]<b[0];
}

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int pSize = persons.size();
        vector<int> indices(pSize);// 给人排序
        iota(indices.begin(),indices.end(),0); // 初始化，从0开始递增的序列
        sort(indices.begin(),indices.end(), [&](int i, int j){return persons[i]<persons[j];});
        
        map<int, int> diff; // 有序的hash，key记录日期
        for(auto& flower:flowers){
            diff[flower[0]]++;
            diff[flower[1]+1]--;
        }

        vector<int> ans(pSize);
        auto it = diff.begin();
        int sum = 0;
        for(int id:indices){
            while(it!=diff.end() && it->first<=persons[id]){ // 遍历一次花
                sum += it->second;
                it++;
            }
            ans[id] = sum;
            cout<<ans[id]<<endl;
        }
        
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> flowers(6);
    vector<int> person {31,45,41,48};
    flowers[0].push_back(28);
    flowers[0].push_back(37);
    flowers[1].push_back(23);
    flowers[1].push_back(33);
    flowers[2].push_back(39);
    flowers[2].push_back(39);
    flowers[3].push_back(49);
    flowers[3].push_back(50);
    flowers[4].push_back(41);
    flowers[4].push_back(45);
    flowers[5].push_back(14);
    flowers[5].push_back(47);
    s.fullBloomFlowers(flowers,person);
    system("pause");
    return 0;
}