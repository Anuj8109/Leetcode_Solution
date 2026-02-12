class Solution {
    public int countBinarySubstrings(String s) {
        // Count consecutive 0 or 1
        // 000111


        int index = 0;
        int len = s.length();
        int prev = 0;
        int res = 0;
        while(index < len){
            int count = 1;
            index++;
            while(index < len && s.charAt(index) == s.charAt(index - 1)){
                count++;
                index++;
            }
            res += Math.min(prev, count);
            prev = count;
        }
        return res;
    }
}