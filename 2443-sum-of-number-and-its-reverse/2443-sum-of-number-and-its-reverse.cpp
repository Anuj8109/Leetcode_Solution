class Solution {
public:
    static int reverse(int num) {
        int ans = 0;
        while (num) {
            int d = num % 10;
            num /= 10;
            ans *= 10;
            ans += d;
        }
        return ans;
    }
    bool sumOfNumberAndReverse(int num) {
        for(int i=num/2;i<=num;i++){
            if(i + reverse(i) == num) return 1;
        }
        return 0;
    }
};