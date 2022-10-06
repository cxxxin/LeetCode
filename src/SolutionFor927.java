import java.util.Arrays;

/**
 * 927. 三等分
 * 思路：模拟方法：按1的个数划分
 */

public class SolutionFor927 {
    public int[] threeEqualParts(int[] arr) {
        int sum = Arrays.stream(arr).sum(); // 统计1的个数
        if (sum%3!=0)
            return new int[]{-1, -1};

        if (sum==0){ // 没有1
            return new int[] {0, 2};
        }

        int partial = sum/3;
        int first = 0, second = 0, third = 0 , curr = 0; // 找到每一节来说第一个1出现的位置
        for (int i=0;i<arr.length;i++){
            if (arr[i] == 1){
                if (curr == 0){
                    first = i;
                }
                else if (curr == partial){
                    second = i;
                }
                else if (curr == 2*partial){
                    third = i;
                }

                curr++;
            }
        }

        // 开始检查间隔的0数量对不对
        int len = arr.length - third;
        if (first + len <= second && second + len <= third){ // 不满足这个条件的话说明third后的位可能会太多  前面凑不出来
            int i = 0;
            while (third + i < arr.length){ // 开始遍历
                if (arr[first+i] != arr[second + i] || arr[first+i] != arr[third+i]){
                    return new int[]{-1, -1};
                }
                i++;
            }
            return new int[]{first+len-1, second+len};
        }

        return new int[]{-1, -1};
    }
}
