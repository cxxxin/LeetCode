#include <iostream>
#include <vector>
#include <random>
#include <unordered_map>
using namespace std;

/*
 随机数索引

 给你一个可能含有 重复元素 的整数数组 nums ，请你随机输出给定的目标数字 target 的索引。你可以假设给定的数字一定存在于数组中。

实现 Solution 类：
Solution(int[] nums) 用数组 nums 初始化对象。
int pick(int target) 从 nums 中选出一个满足 nums[i] == target 的随机索引 i 。
如果存在多个有效的索引，则每个索引的返回概率应当相等。
*/

/*
思路：
    如何具备快速搜索的能力？哈希表
*/

class Solution {
private:
    unordered_map<int,vector<int>> pos; // record num->pos
public:
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            pos[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int> possiblePos = pos[target];
        return possiblePos[random()%possiblePos.size()];
    }
};


int main(){
    return 0;
}