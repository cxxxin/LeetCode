#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
using namespace std;

/*
下一个更大元素 I

nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。
给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。

对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，
并且在 nums2 确定 nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。

返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。
*/

/*
思路：
    单调栈 + 哈希表
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp; // <curr,bigger>
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            int num = nums2[i]; // current num
            while(!st.empty() && num >= st.top()){ // st保留
                st.pop();
            }
            mp[num] = st.empty()?-1:st.top();
            st.push(num);
        }
        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};

int main(){
    return 0;
}