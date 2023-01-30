class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        else if(n == 1 || n == 2) return 1;
        int p = 0, q = 1,r = 1;
        int x;
        while(n > 2){
            x = p + q + r;
            p = q;
            q = r;
            r = x;
            n--;
        }
        return x;
    }
};