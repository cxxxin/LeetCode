#include <iostream>
#include <cmath>
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
        
        int l = 0;
        int r = height.size()-1;

        while (l<r)
        {
            int v = min(height[l],height[r]*(r-l));
            ans = max(ans, v);

            if(height[l]<=height[r]){ // 之后l再怎么右移，都会比当前的v更小
                l++;
            }
            else{ // 之后r再怎么左移，都会比当前的v更小
                r--;
            }
        }
        
        return ans;
    }
};


int main(){
    Solution s;
    vector<int> example = [1,8,6,2,5,4,8,3,7];
    int result = s.maxArea(example);
    cout<<result<<endl;
    system("pause");
    return 0;
}