class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return 0;
        long temp = 0;
        long pp = x;
        while(x > 0){
            temp = temp*10 + x % 10;
            x = x/10;
        }
        return pp == temp;
    }
};