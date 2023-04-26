class Solution {
public:
    int addDigits(int num) {
//         if(num >= 0 && num < 10) return num;
        
//         int ans = 0;
//         while(num > 0){
//             ans += num % 10;
//             num = num/10;
//         }
//         return addDigits(ans);
        if(num) return 1 + (num - 1)%9;
        return num;
    }
};