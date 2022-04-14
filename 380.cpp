#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>
#include <time.h>

using namespace std;

/*
O(1) 时间插入、删除和获取随机元素

实现RandomizedSet 类：

RandomizedSet() 初始化 RandomizedSet 对象
bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 相同的概率 被返回。
你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。

*/


/*
思路：
    变长数组中存储元素，哈希表中存储每个元素在变长数组中的下标。
*/

class RandomizedSet {
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if(index.count(val)){
            return false;
        }
        int n = value.size();
        value.emplace_back(val);
        index[val] = n;
        return true;
    }
    
    bool remove(int val) { // 把vector的最后一项和val交换
        if(!index.count(val){
            return false;
        }
        int n = index[val];
        int last = value.back();
        value[n] = last;
        value.pop_back();
        index[last] = n;
        index.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand()%nums.size();
        return value[randomIndex];
    }

private:
    vector<int> value;
    unordered_map<int,int> index; // <value,index>
};

int main(){
    return 0;
}