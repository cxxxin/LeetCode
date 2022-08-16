/**
 * 1656. 设计有序流
 * 思路：模拟
 */

import java.util.ArrayList;
import java.util.List;

public class SolutionFor1656 {
    private String[] stream;
    private int ptr;

    public SolutionFor1656(int n) {
        ptr = 1;
        stream = new String[n+1]; // n+1是因为题目要求ptr从1开始
    }

    public List<String> insert(int idKey, String value) {
        stream[idKey] = value;
        List<String> res = new ArrayList<String>();
        while (ptr < stream.length && stream[ptr]!=null){
            res.add(stream[ptr]);
            ptr++;
        }
        return res;
    }
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream obj = new OrderedStream(n);
 * List<String> param_1 = obj.insert(idKey,value);
 */