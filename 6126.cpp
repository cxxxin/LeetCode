#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

/*
6126. 设计食物评分系统
*/

/*
思路：
    数据结构题
*/

class FoodRatings {
private:
    unordered_map<string, pair<int, string>> fs;
    unordered_map<string, set<pair<int, string>>> cs;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0;i<n;i++){
            auto &f = foods[i], &c = cuisines[i];
            int r = ratings[i];
            fs[f] = {r, c};
            cs[c].emplace(-r, f); // pair的比大小方式：先按first比较，如果相等，再按照second比较  取负数的原因是这样头部就是最大的
        }
    }
    
    void changeRating(string food, int newRating) {
       string c = fs[food].second;
       int r = fs[food].first;
       auto &set = cs[c];
       set.erase({-r, food}); // remove
       set.emplace(-newRating, food);
       fs[food].first = newRating;
    }
    
    string highestRated(string cuisine) {
        return cs[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

int main(){
    return 0;
}