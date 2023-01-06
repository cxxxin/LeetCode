/**
 * 215. 数组中的第K个最大元素
 * 思路：建立一个大根堆，不停移走第一个元素
 */

public class Solution2For215 {
    public int findKthLargest(int[] nums, int k) {
        // 建立大根堆
        int n = nums.length;
        buildMaxHeap(nums, n);

        // 不断把最大的节点移到数组末尾，然后重新调整前面的数组为新的大根堆
        for (int i=n-1;i>=n-k+1;i--){
            swap(nums, 0, i);
            maxHeapify(nums, 0, i);
        }

        // 大根堆的顶端
        return nums[0];
    }

    // utils
    public void buildMaxHeap(int[] a, int heapSize){ // 从最后一个非叶子结点开始进行调整，从左到右，从下到上
        for (int i=heapSize/2;i>=0;i--){
            maxHeapify(a, i, heapSize);
        }
    }

    public void maxHeapify(int[] a, int i, int heapSize){ // adjust 对于索引为i的节点，调整它的位置
        int l = i*2+1, r = i*2+2, largest = i; // l和r都是节点i的子节点（如果有的话），我们要递归调整i到在该在的位置为止
        if (l < heapSize && a[l] > a[largest]){
            largest = l;
        }
        if (r < heapSize && a[r] > a[largest]){
            largest = r;
        }
        if (largest != i){ // 节点i的位置发生了改变
            swap(a, i, largest);
            maxHeapify(a, largest, heapSize);
        }
    }

    public void swap(int[] a, int i, int j){
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
