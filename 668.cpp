#include <iostream>
using namespace std;

/*
乘法表中第k小的数

几乎每一个人都用 乘法表。但是你能在乘法表中快速找到第k小的数字吗？
给定高度m 、宽度n 的一张 m * n的乘法表，以及正整数k，你需要返回表中第k 小的数字。
*/

/*
思路：
    矩阵每行每列是递增的  所以可以二分
*/

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1;
        int r = m*n;
        while(l < r){
            int mid = (l+r)>>1;
            int count = getCnt(mid,m,n);
            if(count>=k) r = mid;
            else l = mid+1;
        }
        return r;
    }

    int getCnt(int mid, int m, int n){
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans += i*m<=mid? m : mid/i;
        }
        return ans;
    }
};

int main()[
    return 0;
]