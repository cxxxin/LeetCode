public class SolutionFor667 {
    class Solution {
        public int[] constructArray(int n, int k) {
            int[] res = new int[n];
            int p = 1, q = n;
            for (int i=0;i<k;i++){
                if (i%2==0){
                    res[i] = p++;
                }
                else{
                    res[i] = q--;
                }
            }

            if (k%2==0){ // 降序序列
                for (int i=k;i<n;i++){
                    res[i] = q--;
                }
            }
            else {
                for (int i=k;i<n;i++){
                    res[i] = p++;
                }
            }

            return res;
        }
    }
}
