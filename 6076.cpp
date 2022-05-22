#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
6076. 表示一个折线图的最少线段数

给你一个二维整数数组 stockPrices ，其中 stockPrices[i] = [dayi, pricei] 表示股票在 dayi 的价格为 pricei 。
折线图 是一个二维平面上的若干个点组成的图，横坐标表示日期，纵坐标表示价格，折线图由相邻的点连接而成。
*/

/*
思路：
    其实就是判断和和前面那点连成的直线斜率和之前的是否一样
*/


bool MyCmp (const vector<int>& v1, const vector<int>& v2){
    return v1[0]<v2[0];
}


class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size();
        if(n==1) return 0;
        if(n==2) return 1;
        sort(stockPrices.begin(),stockPrices.end(),MyCmp);
        map<long long, long long> mp;
        for(int i=0;i<n;i++){
            mp[stockPrices[i][0]] = stockPrices[i][1];
        }

        int ans = 1;
        int prev = 0, med = 1, curr = 2;
        for(;curr<n;curr++,med++,prev++){
            if((long long)(stockPrices[curr][1]-stockPrices[med][1])*
            (long long)(stockPrices[med][0]-stockPrices[prev][0]) 
            != (long long)(stockPrices[med][1]-stockPrices[prev][1])*
            (long long)(stockPrices[curr][0]-stockPrices[med][0])){
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    // [[72,98],[62,27],[32,7],[71,4],[25,19],[91,30],[52,73],[10,9],[99,71],[47,22],[19,30],[80,63],[18,15],[48,17],[77,16],[46,27],[66,87],[55,84],[65,38],[30,9],[50,42],[100,60],[75,73],[98,53],[22,80],[41,61],[37,47],[95,8],[51,81],[78,79],[57,95]]
    return 0;
}