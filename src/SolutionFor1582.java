public class SolutionFor1582 {
    class Solution {
        public int numSpecial(int[][] mat) {
            int res = 0;
            int m = mat.length, n = mat[0].length;
            int[] rows = new int[m]; // 记录每一行的和
            int[] cols = new int[n]; // 记录每一列的和
            for (int i=0;i<m;i++){
                for (int j=0;j<n;j++){
                    if (mat[i][j] == 1){
                        rows[i]++;
                        cols[j]++;
                    }
                }
            }

            for (int i=0;i<m;i++){
                for (int j=0;j<n;j++){
                    if (mat[i][j]==1 && rows[i]==1 && cols[j]==1)
                        res++;
                }
            }
            return res;
        }
    }
}
