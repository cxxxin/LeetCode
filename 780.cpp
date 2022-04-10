#include<iostream>

using namespace std;

/*
到达终点

给定四个整数 sx , sy ，tx 和 ty，如果通过一系列的转换可以从起点 (sx, sy) 到达终点 (tx, ty)，
则返回 true，否则返回 false。
从点 (x, y) 可以转换到 (x, x+y)  或者 (x+y, y)。
*/

/*
思路：
    有点斐波那契数列？可以逆着往前来？
    1 <= sx, sy, tx, ty <= 10^9
    因为xy都是正数，x+y肯定是比x和y都更大的，所以通过逆推，我们每次都可以唯一确定到底哪个是x+y，结果是唯一的，就不需要
    通过回溯来穷举所有可能性。
*/

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > sx && ty > sy && tx != ty)
        {
            if (tx > ty) // tx = x+y
            {
                tx %= ty;
            }
            else if (tx < ty)
            {
                ty %= tx;
            }                 
        }
        if (tx == sx && ty == sy) 
            return true;

        if (tx == sx) // 只有x是相等的话，则看y能不能通过一直-x恢复回去
            return ty > sy && (ty - sy) % tx == 0;
        
        if (ty == sy)
            return tx > sx && (tx-sx) % ty == 0;

        return false;
        
    }
};

int main(){
    return 0;
}