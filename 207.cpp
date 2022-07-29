#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
207. 课程表

你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，
其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
*/

/*
思路：
    拓扑排序
*/

class Solution {
private:
    vector<vector<int>> edges;
    vector<int> indeg; // 入度
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for(auto& info:prerequisites){
            edges[info[1]].push_back(info[0]); // 由info1指向info0的边
            indeg[info[0]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        int visited = 0;
        while(!q.empty()){
            visited++;
            int curr = q.front();
            q.pop();
            for(int next:edges[curr]){
                indeg[next]--;
                if(indeg[next]==0){
                    q.push(next);
                }
            }
        }

        return visited == numCourses;
    }
};

int main(){
    return 0;
}