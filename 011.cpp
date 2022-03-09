#include <iostream>
#include <string>
#include <climits>
#include <vector>

using namespace std;

/*
盛最多水的容器
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
返回容器可以储存的最大水量。
说明：你不能倾斜容器。
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;

        // 开辟一个数组来记录每个组合的盛水量
        vector<vector<int>> v;
        for(int i=0;i<height.size()-1;i++){
            for(int j=i+1;j<height.size();j++){
                v[i][j] = (j-1)*max(height[i],height[j]);
            }
        }

        ans = max(v);

        return ans;
    }
};


int main(){
    Solution s;
    int result = s.maxArea([1,8,6,2,5,4,8,3,7]);
    cout<<result<<endl;
    system("pause");
    return 0;
}