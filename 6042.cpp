#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
统计圆内格点数目

给你一个二维整数数组 circles ，其中 circles[i] = [xi, yi, ri] 表示网格上圆心为 (xi, yi) 且半径为 ri 的第 i 个圆，
返回出现在 至少一个 圆内的 格点数目 。

注意：

格点 是指整数坐标对应的点。
圆周上的点 也被视为出现在圆内的点。
*/

/*
*/


class Solution {
public:
    bool inCircle(vector<int>& circle, int x, int y){
        return (x-circle[0])*(x-circle[0])+(y-circle[1])*(y-circle[1]) <= circle[2]*circle[2];
    }

    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>> points;
        int ans = 0;
        for(vector<int> circle:circles){
            int x = circle[0];
            int y = circle[1];
            int r = circle[2];
            for(int i=x-r;i<=x+r;i++){
                for(int j=y-r;j<=y+r;j++){
                    if(points.count(make_pair(i,j)))
                        continue;
                    if(inCircle(circle,i,j)){
                        points.emplace(make_pair(i,j));
                    }
                }
            }
        }
        return points.size();
    }
};

int main(){
    vector<vector<int>> example(1);
    example[0].push_back(2);
    example[0].push_back(2);
    example[0].push_back(1);
    Solution s;
    cout<<s.countLatticePoints(example)<<endl;
    system("pause");
    return 0;
}