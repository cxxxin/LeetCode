/**
 * 2383. 赢得比赛需要的最少训练时长
 * 思路：贪心
 */

public class SolutionFor2383 {
}

class Solution {
    public int minNumberOfHours(int initialEnergy, int initialExperience, int[] energy, int[] experience) {
        int n = energy.length;
        int res = 0;
        for (int i=0;i<n;i++){
            if (initialEnergy<=energy[i]){
                int t = energy[i] - initialEnergy + 1;
                res += t;
                initialEnergy += t;
            }
            if (initialExperience<=experience[i]){
                int t = experience[i] - initialExperience + 1;
                res += t;
                initialExperience += t;
            }

            initialEnergy -= energy[i];
            initialExperience += experience[i];
        }

        return res;
    }
}