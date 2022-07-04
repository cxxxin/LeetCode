#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
1200. 最小绝对差

给你个整数数组 arr，其中每个元素都 不相同。
请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。
*/

/*
思路：
    先排序
*/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int minDiff = INT32_MAX, n = arr.size();
        for(int i=1;i<n;i++){
            if ((arr[i]-arr[i-1]) < minDiff){
                ans.clear();
                ans.push_back({arr[i-1],arr[i]});
                minDiff = arr[i]-arr[i-1];
            }
            else if ((arr[i]-arr[i-1]) == minDiff){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}