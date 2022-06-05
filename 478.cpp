#include <iostream>
#include <vector>
#include <random>
using namespace std;

/*
在圆内随机生成点
*/

/*
思路：
    拒绝采样，随机生成正方形内的点，不符合就重来
*/

class Solution {
public:
    double radius, x_center, y_center;
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;
    Solution(double radius, double x_center, double y_center):dis(-radius,radius) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    vector<double> randPoint() {
        while(true){
            double x = dis(gen), y = dis(gen);
            if(x*x + y*y <= radius*radius){
                return {x_center+x,y_center+y};
            }
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

int main(){
    return 0;
}