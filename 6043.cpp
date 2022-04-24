#include <iostream>
#include <vector>
using namespace std;

/*
统计包含每个点的矩形数目   
*/

/*
思路：
    排序+二分
*/

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        int rSize = rectangles.size();
        int pSize = points.size();
        // 排序

        int i = 0;
        for(vector<int> point:points){
            int x = point[0];
            int y = point[1];
            ans[i] = rSize;
            for(vector<int> rect:rectangles){ // 遍历矩形
                int w = rect[0];
                int h = rect[1];
                if(x>w || y>h){ // 不在矩形内
                    ans[i]--;
                }
                else{
                    break;
                }
            }
            i++;
        }

        return ans;
    }
};


int main(){
    return 0;
}