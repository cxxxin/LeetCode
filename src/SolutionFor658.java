/**
 * 658. 找到 K 个最接近的元素
 * 思路：二分查找+双指针
 */

import java.util.ArrayList;
import java.util.List;

public class SolutionFor658 {
    class Solution {
        public List<Integer> findClosestElements(int[] arr, int k, int x) {
            int right = binarySearch(arr, x); // >=x
            int left = right-1; // <x
            // 确定范围
            while (k>0){
                if (left<0){ // left不能再左移
                    right++;
                }
                else if (right>=arr.length){ // 不能再右移
                    left--;
                }
                else if (x-arr[left] <= arr[right]-x){ // 左边更接近
                    left--;
                }
                else { // 右边更接近
                    right++;
                }

                k--;
            }
            List<Integer> res = new ArrayList<Integer>();
            for (++left;left<right;left++){
                res.add(arr[left]);
            }
            return res;
        }

        int binarySearch(int[] arr, int x){
            int low = 0, high = arr.length-1;
            while (low<high){
                int mid = (low+high) >> 1;
                if (arr[mid] >= x){
                    high = mid;
                }
                else {
                    low = mid + 1;
                }
            }
            return low; // 一定>=x
        }
    }
}
