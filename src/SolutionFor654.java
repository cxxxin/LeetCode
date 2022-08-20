/**
 * 654. 最大二叉树
 * 思路：按题目说的递归
 */

public class SolutionFor654 {
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return construct(nums, 0, nums.length-1);
    }

    public TreeNode construct(int[] nums, int left, int right) {
        if (left>right){
            return null;
        }

        int best = left;
        for (int i=left+1;i<=right;i++){
            if (nums[i] > nums[best]){
                best = i; // 找最大值的索引
            }
        }
        TreeNode node = new TreeNode(nums[best]);
        node.left = construct(nums, left, best-1);
        node.right = construct(nums, best+1, right);
        return node;
    }
}
