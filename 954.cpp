#include <iostream>
#include <vector>

using namespace std;

/*
二倍数对数组

给定一个长度为偶数的整数数组 arr，只有对 arr 进行重组后可以满足 “对于每个 0 <= i < len(arr) / 2，
都有 arr[2 * i + 1] = 2 * arr[2 * i]” 时，返回 true；否则，返回 false。
*/

class Solution {
public:
    bool canReorderDoubled(vector<int> &arr) {
        unordered_map<int, int> cnt;
        for (int x : arr) {
            ++cnt[x];
        }
        if (cnt[0] % 2) { // 0的2倍是0，有奇数个0的时候，会多余出一个0没得匹配
            return false;
        }

        vector<int> vals;
        vals.reserve(cnt.size());
        for (auto &[x, _] : cnt) {
            vals.push_back(x); // 把存在的数存在vals里
        }
        sort(vals.begin(), vals.end(), [](int a, int b) { return abs(a) < abs(b); });

        for (int x : vals) {
            if (cnt[2 * x] < cnt[x]) { // 无法找到足够的 2x 与 x 配对
                return false;
            }
            cnt[2 * x] -= cnt[x];
        }
        return true;
    }
};


int main(){
    retur 0;
}