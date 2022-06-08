#include <iostream>
#include <vector>

using namespace std;

/*
有效的回旋镖

给定一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点，如果这些点构成一个 回旋镖 则返回 true 。
回旋镖 定义为一组三个点，这些点 各不相同 且 不在一条直线上 。
*/

/*
思路：
    比斜率
*/

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        for(int i=0;i<3;i++){
            if(points[i][0]==points[(i+3-1)%3][0] && points[i][1]==points[(i+3-1)%3][1])
                return false;
        }
        if((points[1][1]-points[0][1])*(points[2][0]-points[1][0]) == (points[2][1]-points[1][1])*(points[1][0]-points[0][0])){
            return false;
        }

        return true;
    }
};

int main(){
    return 0;
}