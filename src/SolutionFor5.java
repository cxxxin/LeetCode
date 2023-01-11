/**
 * 5. 最长回文子串
 * 思路：dp
 */

public class SolutionFor5 {
    public String longestPalindrome(String s) {
        int n = s.length();
        boolean[][] dp = new boolean[n][n];
        int maxCnt = 0;
        int start = 0, end = 0;

        // init
        for (int i=0;i<n;i++){
            dp[i][i] = true;
            if (dp[i][i]){
                maxCnt = 1;
                start = i;
                end = i;
            }
        }
        for (int i=0;i<n-1;i++){
            dp[i][i+1] = s.charAt(i) == s.charAt(i+1);
            if (dp[i][i+1]){
                maxCnt = 2;
                start = i;
                end = i+1;
            }
        }

        // dp
        for (int i=n-2;i>=0;i--){
            for (int j=i+2;j<n;j++){
                dp[i][j] = s.charAt(i) == s.charAt(j) && dp[i + 1][j - 1];
                if (dp[i][j] && j-i+1>maxCnt){
                    maxCnt = j-i+1;
                    start = i;
                    end = j;
                }
            }
        }

        return s.substring(start, end+1);
    }
}
