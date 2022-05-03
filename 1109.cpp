#include <iostream>
#include <vector>
using namespace std;

/*
航班预定统计

这里有 n 个航班，它们分别从 1 到 n 进行编号。
有一份航班预订表 bookings ，表中第 i 条预订记录 bookings[i] = [firsti, lasti, seatsi] 
意味着在从 firsti 到 lasti （包含 firsti 和 lasti ）的 每个航班 上预订了 seatsi 个座位。
请你返回一个长度为 n 的数组 answer，里面的元素是每个航班预定的座位总数。
*/

/*
思路：
    前缀和
    用一个vector记录每趟航班之间的差值
*/

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+1);
        vector<int> ans(n);
        for(vector<int> booking:bookings){
            diff[booking[0]-1] += booking[2];
            diff[booking[1]] -= booking[2];
        }

        ans[0] = diff[0];
        for(int i=1;i<n;i++){
            ans[i] = ans[i-1] + diff[i];
        }

        return ans;
    }
};

int main(){
    return 0;
}