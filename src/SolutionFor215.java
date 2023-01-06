import java.util.Random;


/**
 * 215. 数组中的第K个最大元素
 * 思路：基于快速排序的选择方法/堆排序
 */

public class SolutionFor215 {
    Random random = new Random();

    public int findKthLargest(int[] nums, int k) {
        return quickSelect(nums, 0, nums.length-1, nums.length - k);
    }

    // utils
    public int quickSelect(int[] a, int l, int r, int index){
        int q = randomPartition(a, l, r);
        if (q == index){ // 恰巧现在的pilot就是第index个
            return a[q];
        }
        else {
            return q < index ? quickSelect(a, q+1, r, index) : quickSelect(a, l, q-1, index);
        }
    }

    public int randomPartition(int[] a, int l, int r){ // 随机选择pilot
        int i = random.nextInt(r-l+1)+l;
        swap(a, i, r);
        return partition(a, l, r);
    }

    public int partition(int[] a, int l, int r){ // 把小于支点的数都放左边
        int x = a[r], i = l-1;
        for (int j = l;j<r;j++){
            if (a[j] <= x){ // 小于支点
                swap(a, ++i, j);
            }
        }
        swap(a, i+1, r); // 完成此条操作后，i已经指向了pilot的位置
        return i+1; // 因为返回的是个数，所以+1
    }

    public void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
