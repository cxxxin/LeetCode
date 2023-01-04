import java.util.HashMap;
import java.util.Map;

/**
 * 146. LRU 缓存
 * 思路：哈希表+双向链表  哈希表是为了查找速度快
 */

public class SolutionFor146 {
    class DLinkedNode{ // 双向链表的节点
        int key;
        int value;
        DLinkedNode prev;
        DLinkedNode next;
        public DLinkedNode(){}
        public DLinkedNode(int key, int value){this.key = key; this.value = value;}
    }

    private Map<Integer, DLinkedNode> cache = new HashMap<>();
    private int size;
    private int capacity;
    private DLinkedNode head, tail;

    public SolutionFor146(int capacity) {  // LRUCache
        this.size = 0; // 初始化
        this.capacity = capacity;
        // 伪头部节点 and 伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head.next = tail;
        tail.prev = head;
    }

    public int get(int key) {
        DLinkedNode node = cache.get(key);
        if (node == null)
            return -1;
        // 如果 key 存在，先通过哈希表定位，再移到头部
        moveToHead(node); // 模拟最近使用放到头部
        return node.value;
    }

    public void put(int key, int value) {
        DLinkedNode node = cache.get(key);
        if (node == null){ // key 不存在，创建新的节点
            DLinkedNode newNode = new DLinkedNode(key, value);
            cache.put(key, newNode);
            addToHead(newNode);
            size++;
            if (size > capacity){ // 需要移走末位的节点
                DLinkedNode tail = removeTail();
                cache.remove(tail.key);
                size--;
            }
        }
        else { // key 存在，覆盖
            node.value = value;
            moveToHead(node);
        }
    }

    // utils
    private void addToHead(DLinkedNode node){
        node.prev = head;
        node.next = head.next;
        head.next.prev = node;
        head.next = node;
    }

    private void moveToHead(DLinkedNode node){
        removeNode(node);
        addToHead(node);
    }

    private void removeNode(DLinkedNode node){
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    private DLinkedNode removeTail(){
        DLinkedNode res = tail.prev;
        removeNode(res);
        return res;
    }
}
