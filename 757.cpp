#include <iostream>
#include <vector>
using namespace std;

/*
757. 设置交集大小至少为2

一个整数区间 [a, b]  ( a < b ) 代表着从 a 到 b 的所有连续整数，包括 a 和 b。
给你一组整数区间intervals，请找到一个最小的集合 S，使得 S 里的元素与区间intervals中的每一个整数区间都至少有2个元素相交。
输出这个最小集合S的大小。
*/

/*
思路：
    贪心：排序后从后往前进行遍历，
    每次选取与当前交集集合相交为空的区间的最左边的元素即可，
    然后往前判断前面是否有区间能因此产生交集，产生交集的直接跳过即可。
*/

class Solution {
public:
    void help(vector<vector<int>>& intervals, vector<vector<int>>& temp, int pos, int num) {
        for (int i = pos; i >= 0; i--) {
            if (intervals[i][1] < num) {
                break;
            }
            temp[i].push_back(num);
        }
    }

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int res = 0;
        int m = 2;
        // 根据range的左端进行排序，左端相同则右端大的排前面
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        vector<vector<int>> temp(n);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = intervals[i][0], k = temp[i].size(); k < m; j++, k++) {
                res++;
                help(intervals, temp, i - 1, j);
            }
        }
        return res;
    }
};

int main(){
    return 0;
}