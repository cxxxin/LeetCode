#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
1331. 数组序号转换

给你一个整数数组 arr ，请你将数组中的每个元素替换为它们排序后的序号。
序号代表了一个元素有多大。序号编号的规则如下：
- 序号从 1 开始编号。
- 一个元素越大，那么序号越大。如果两个元素相等，那么它们的序号相同。
- 每个数字的序号都应该尽可能地小。
*/

/*
思路：
    排序+哈希
*/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortArr = arr;
        sort(sortArr.begin(),sortArr.end());
        unordered_map<int, int> rcd;
        int cnt = 0;
        for(int num:sortArr){
            if(!rcd.count(num)){
                cnt++;
                rcd[num] = cnt; 
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i] = rcd[arr[i]];
        }
        return arr;
    }
};

int main(){
    return 0;
}