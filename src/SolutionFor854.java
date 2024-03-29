/**
 * 854. 相似度为 K 的字符串
 */

public class SolutionFor854 {
    int ans;

    public int kSimilarity(String s1, String s2) {
        StringBuilder str1 = new StringBuilder();
        StringBuilder str2 = new StringBuilder();
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                str1.append(s1.charAt(i)); // 记录不同之处即可
                str2.append(s2.charAt(i));
            }
        }
        if (str1.length() == 0) {
            return 0;
        }
        ans = str1.length() - 1; // 最多交换n-1次
        dfs(0, 0, str1.length(), str1.toString(), str2.toString());
        return ans;
    }

    public void dfs(int pos, int cost, int len, String str1, String str2) { // cost表示当前已经交换的次数
        if (cost > ans) {
            return;
        }
        while (pos < str1.length() && str1.charAt(pos) == str2.charAt(pos)) {
            pos++;
        }
        if (pos == str1.length()) { // 已经交换完了所有不同的地方！
            ans = Math.min(ans, cost);
            return;
        }
        /* 当前状态的交换次数下限大于等于当前的最小交换次数 */
        if (cost + minSwap(str1, str2, pos) >= ans) { // 相当于剪枝
            return;
        }
        for (int i = pos + 1; i < str1.length(); i++) {
            if (str1.charAt(i) == str2.charAt(pos)) { // str1的i位与str2的pos位是相同的，则交换str1的i与pos位
                String str1Next = swap(str1, i, pos);
                dfs(pos + 1, cost + 1, len, str1Next, str2);
            }
        }
    }

    public int minSwap(String s1, String s2, int pos) { // 不同的个数/2
        int tot = 0;
        for (int i = pos; i < s1.length(); i++) {
            tot += s1.charAt(i) != s2.charAt(i) ? 1 : 0;
        }
        return (tot + 1) / 2;
    }

    public String swap(String cur, int i, int j) { // 交换字母
        char[] arr = cur.toCharArray();
        char c = arr[i];
        arr[i] = arr[j];
        arr[j] = c;
        return new String(arr);
    }
}
