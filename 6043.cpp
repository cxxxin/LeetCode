#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*
统计包含每个点的矩形数目   
*/

/*
思路：
    排序+二分
-----------
    h只有1-100这几种可能，数据量不大的话可以考虑先按x轴排序以后，用hashmap记录y轴不同值对应的数量
*/

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        sort(rectangles.begin(), rectangles.end(), [](auto &a, auto &b) { return a[1] > b[1]; }); // 从大到小排序
        int rSize = rectangles.size();
        int pSize = points.size();

        vector<int> indices(pSize); // 存储排序后points的index，这里不直接对points排序是因为返回答案的时候还是要按顺序
        iota(indices.begin(),indices.end(),0); // 初始化，从0开始递增的序列
        sort(indices.begin(),indices.end(), [&](int i, int j){return points[i][1]>points[j][1];}); // 从大到小排序后的索引

        vector<int> ans(pSize), xs; // xs记录横坐标
        int i = 0;
        for(int id:indices){
            int start = i;
            while(i<rSize && rectangles[i][1]>= points[id][1]){
                xs.push_back(rectangles[i++][0]); // 将所有的
            }
            // 如果xs中插入了新元素，则重新排序 其实可以用一开始就xs用堆排序会更快
            if(start<i)
                sort(xs.begin(),xs.end());
            ans[id] = i-(lower_bound(xs.begin(),xs.end(),points[id][0])-xs.begin()); // lowerbound得到xs中该存放points[id][0]的指针
        }
        return ans;
    }
};


int main(){
    return 0;
}