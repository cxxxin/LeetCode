#include <iostream>
#include <vector>
using namespace std;

/*
593. 有效的正方形

给定2D空间中四个点的坐标 p1, p2, p3 和 p4，如果这四个点构成一个正方形，则返回 true 。
点的坐标 pi 表示为 [xi, yi] 。输入 不是 按任何顺序给出的。
一个 有效的正方形 有四条等边和四个等角(90度角)。
*/

/*
思路：
    判别正方形的一般顺序为先说明它是平行四边形；再说明它是菱形（或矩形）；最后说明它是矩形（或菱形）。
    - 如果两条斜边的中点相同：则说明以该两条斜边组成的四边形为「平行四边形」。
    - 在满足「条件一」的基础上，如果两条斜边的长度相同：则说明以该两条斜边组成的四边形为「矩形」。
    - 在满足「条件二」的基础上，如果两条斜边的相互垂直：则说明以该两条斜边组成的四边形为「正方形」。

    以上是官解，其实我觉得验证是有三个直角的四边形也可以。
*/

class Solution {
public:
    bool checkLength(vector<int>& v1, vector<int>& v2) {
        return (v1[0] * v1[0] + v1[1] * v1[1]) == (v2[0] * v2[0] + v2[1] * v2[1]);
    }

    bool checkMidPoint(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return (p1[0] + p2[0]) == (p3[0] + p4[0]) && (p1[1] + p2[1]) == (p3[1] + p4[1]);
    }

    int calCos(vector<int>& v1, vector<int>& v2) {
        return (v1[0] * v2[0] + v1[1] * v2[1]) == 0;
    }

    bool help(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> v1 = {p1[0] - p2[0], p1[1] - p2[1]};
        vector<int> v2 = {p3[0] - p4[0], p3[1] - p4[1]};
        if (checkMidPoint(p1, p2, p3, p4) && checkLength(v1, v2) && calCos(v1, v2)) {
            return true;
        } 
        return false;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if (p1 == p2) {
            return false;
        }
        if (help(p1, p2, p3, p4)) {
            return true;
        }
        if (p1 == p3) {
            return false;
        }
        if (help(p1, p3, p2, p4)) {
            return true;
        }
        if (p1 == p4) {
            return false;
        }
        if (help(p1, p4, p2, p3)) {
            return true;
        }
        return false;
    }
};


int main(){
    return 0;
}