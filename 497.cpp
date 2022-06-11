#include <iostream>
#include <vector>
#include <random>

using namespace std;

/*
非重叠矩形中的随机点

给定一个由非重叠的轴对齐矩形的数组 rects ，
其中 rects[i] = [ai, bi, xi, yi] 表示 (ai, bi) 是第 i 个矩形的左下角点，(xi, yi) 是第 i 个矩形的右上角点。
设计一个算法来随机挑选一个被某一矩形覆盖的整数点。矩形周长上的点也算做是被矩形覆盖。所有满足要求的点必须等概率被返回。

在给定的矩形覆盖的空间内的任何整数点都有可能被返回。
*/

/*
思路：  
    轮盘赌
*/

class Solution {
private:
    vector<int> arr;
    vector<vector<int>>& rects;
    mt19937 gen{random_device{}()};

public:
    Solution(vector<vector<int>>& rects) : rects(rects){
        this->arr.emplace_back(0);
        for(vector<int>& rect:rects){
            this->arr.emplace_back(arr.back()+(rect[2]-rect[0]+1)*(rect[3]-rect[1]+1)); // 和arr.back()加在一起是为了轮盘赌
        }
    }
    
    vector<int> pick() {
        uniform_int_distribution<int> dis(0, arr.back() - 1); // 可以随机取的范围
        int k = dis(gen) % arr.back(); // 生成一个随机数
        int rectIndex = upper_bound(arr.begin(), arr.end(), k) - arr.begin()-1; // real 可选点的编号
        k -= arr[rectIndex];
        int a = rects[rectIndex][0], b = rects[rectIndex][1]; // ab是选中的矩形的左下角
        int y = rects[rectIndex][3]; // y是选中的矩形的右上角的纵坐标
        int col = y - b + 1; // 可选的范围的行数
        int da = k / col; // delta a
        int db = k - col * da; // delta b
        return {a + da, b + db};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

int main(){
    return 0;
}