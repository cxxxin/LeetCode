import java.util.ArrayList;
import java.util.List;

/**
 * 143. 重排链表
 * 思路：利用线性表存储该链表
 */

public class SolutionFor143 {
    public void reorderList(ListNode head) {
        if (head == null)
            return;

        List<ListNode> list = new ArrayList<>();
        ListNode node = head;
        while (node != null){
            list.add(node);
            node = node.next;
        }

        int i = 0, j = list.size() - 1;
        while (i<j){
            list.get(i).next = list.get(j);
            i++;
            if (i == j) // 到中点了
                break;
            list.get(j).next = list.get(i);
            j--;
        }
        list.get(i).next = null; // 尾部处理
    }
}
