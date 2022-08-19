import java.util.Arrays;

/**
 * 1450. 在既定时间做作业的学生人数
 * 思路：针对queryTime找到startTime中更小的数的索引，找到endTime中更大的数的索引，看看重叠部分的长度。换而言之，二分查找即可。
 */

public class SolutionFor1450 {
    public int busyStudent(int[] startTime, int[] endTime, int queryTime) {
        Arrays.sort(startTime);
        Arrays.sort(endTime);
        int lessStart = upperbound(startTime, 0, startTime.length-1, queryTime);
        int lessEnd = lowerbound(endTime, 0, endTime.length-1, queryTime);
        return lessStart - lessEnd;
    }

    public static int upperbound(int[] arr, int l, int r, int target){
        int ans = r+1;
        while (l<=r){
            int mid = l + ((r-l)>>1);
            if (arr[mid] > target){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }

    public static int lowerbound(int[] arr, int l, int r, int target){
        int ans = r+1;
        while (l<=r){
            int mid = l + ((r-l)>>1);
            if (arr[mid]>=target){
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
}
