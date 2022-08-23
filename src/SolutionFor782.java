/**
 * 782. 变为棋盘
 */

class SolutionFor782 {
    int n = 0, INF = 0x3f3f3f3f;
    int getCnt(int a, int b) {
        return Integer.bitCount(a) != Integer.bitCount(b) ? INF : Integer.bitCount(a ^ b) / 2;
    }
    public int movesToChessboard(int[][] g) {
        n = g.length;
        int r1 = -1, r2 = -1, c1 = -1, c2 = -1, mask = (1 << n) - 1;
        for (int i = 0; i < n; i++) {
            int a = 0, b = 0;
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 1) a += (1 << j);
                if (g[j][i] == 1) b += (1 << j);
            }
            if (r1 == -1) r1 = a;
            else if (r2 == -1 && a != r1) r2 = a;
            if (c1 == -1) c1 = b;
            else if (c2 == -1 && b != c1) c2 = b;
            if (a != r1 && a != r2) return -1;
            if (b != c1 && b != c2) return -1;
        }
        if (Integer.bitCount(r1) + Integer.bitCount(r2) != n) return -1;
        if (Integer.bitCount(c1) + Integer.bitCount(c2) != n) return -1;
        if ((r1 ^ r2) != mask || (c1 ^ c2) != mask) return -1;
        int t = 0;
        for (int i = 0; i < n; i += 2) t += (1 << i);
        int ans = Math.min(getCnt(r1, t), getCnt(r2, t)) + Math.min(getCnt(c1, t), getCnt(c2, t));
        return ans >= INF ? -1 : ans;
    }
}
