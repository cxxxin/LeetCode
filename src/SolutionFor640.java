/**
 * 640. 求解方程
 * 思路：模拟题
 */
public class SolutionFor640 {
    public String solveEquation(String equation) {
        int factor = 0, val = 0; // factor=k   val = b-y
        int index = 0, n = equation.length(), sign1 = 1; // sign1用于标识当前在等号的哪一边
        while (index<n){
            if (equation.charAt(index) == '='){
                sign1 = -1;
                index++;
                continue;
            }

            int sign2 = sign1, number = 0; // sign2标识当前项的正负
            boolean valid = false;
            if (equation.charAt(index)=='-'||equation.charAt(index)=='+'){ // 每一项的符号
                sign2 = (equation.charAt(index)=='-')?-sign1:sign1;
                index++;
            }
            while (index<n && Character.isDigit(equation.charAt(index))){ // 算出这个数 可能是k也可能是b
                number = number*10 + (equation.charAt(index) - '0');
                index++;
                valid = true;
            }
            if (index<n && equation.charAt(index)=='x'){ // kx
                factor += valid ? sign2*number : sign2;
                index++;
            }
            else { // b
                val += sign2*number;
            }
        }

        if (factor==0){ // x被抵消
            return val==0 ? "Infinite solution" : "No solution";
        }

        return "x=" + (-val/factor);
    }
}

