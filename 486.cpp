#include <iostream>
#include <vector>
using namespace std;

/*
预测赢家

给你一个整数数组 nums 。玩家 1 和玩家 2 基于这个数组设计了一个游戏。

玩家 1 和玩家 2 轮流进行自己的回合，玩家 1 先手。开始时，两个玩家的初始分值都是 0 。
每一回合，玩家从数组的任意一端取一个数字（即，nums[0] 或 nums[nums.length - 1]），
取到的数字将会从数组中移除（数组长度减 1 ）。玩家选中的数字将会加到他的得分上。当数组中没有剩余数字可取时，游戏结束。

如果玩家 1 能成为赢家，返回 true 。如果两个玩家得分相等，同样认为玩家 1 是游戏的赢家，也返回 true 。
你可以假设每个玩家的玩法都会使他的分数最大化。
*/  

/*
思路：
    递归，玩家1得分就+，玩家2得分就-
*/

class Solution {
public:
    int total(vector<int>& nums, int l, int r,int turn){
        if(l==r){
            return nums[l]*turn;
        }

        int selectL = nums[l]*turn + total(nums,l+1,r,-turn);
        int selectR = nums[r]*turn + total(nums,l,r-1,-turn);
        return max(selectL*turn,selectR*turn)*turn; // 如果是玩家2的话，selectL和selectR应该是越小越好的，所以取个反比较
    }

    bool PredictTheWinner(vector<int>& nums) {
        return total(nums,0,nums.size()-1,1)>=0;
    }
};

int main(){
    return 0;
}