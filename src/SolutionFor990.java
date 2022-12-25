/**
 * 990. 等式方程的可满足性
 * 思路：并查集 先遍历等式，然后遍历不等式
 */

public class SolutionFor990 {
    class UnionTree{
        private int[] parent;
        private int[] rank;

        UnionTree(){
            parent = new int[26];
            rank = new int[26];

            for (int i=0;i<26;i++){
                parent[i] = i;
            }
        }

        void union(int x, int y){
            int rootx = find(x), rooty = find(y);
            if (rootx == rooty)
                return;

            if (rank[rootx] > rank[rooty]){
                parent[rooty] = rootx;
            }
            else if (rank[rootx] < rank[rooty]){
                parent[rootx] = rooty;
            }
            else {
                parent[rooty] = rootx;
                rank[rootx]++;
            }
        }

        int find(int x){
            if (parent[x] == x){
                return x;
            }

            parent[x] = find(parent[x]);
            return parent[x];
        }

        boolean check(int x, int y){
            return find(x) == find(y);
        }
    }

    public boolean equationsPossible(String[] equations) {
        UnionTree uni = new UnionTree();
        boolean res = true;
        // 遍历等式
        for (String eq:equations){
            if (eq.contains("==")){
                uni.union(eq.charAt(0)-'a', eq.charAt(3)-'a');
            }
        }

        // 遍历不等式
        for (String eq:equations){
            if (eq.contains("!=")){
                if (uni.check(eq.charAt(0)-'a', eq.charAt(3)-'a')){
                    res = false;
                    break;
                }
            }
        }

        return res;
    }
}
