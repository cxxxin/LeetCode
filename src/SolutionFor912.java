import java.util.Random;

/**
 * 912. 排序数组
 * 思路：手写快排，递归解决
 */

public class SolutionFor912 {
    Random random = new Random();
    public int[] sortArray(int[] nums) {
        randomPartition(nums, 0, nums.length-1);
        return nums;
    }

    // utils
    public void randomPartition(int[] a, int l, int r){ // 随机地选择pilot，直到数组的长度为1
        // 递归出口  当前数组为1
        if (r <= l)
            return;

        int pilot = random.nextInt(r-l+1)+l;
        swap(a, r, pilot);
        pilot = partition(a, l, r);
        randomPartition(a, l, pilot-1);
        randomPartition(a, pilot+1, r);
    }

    public int partition(int[] a, int l, int r){ // 把所有小于等于pilot的数都放到pilot左边，并返回pilot的下标
        int x = a[r];
        int i = l;
        for (int j=l;j<r;j++){
            if (a[j] <= x){
                swap(a, i++, j);
            }
        }
        swap(a, i, r);
        return i;
    }

    public void swap(int[] a, int i, int j){
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
