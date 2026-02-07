class Solution {
    public int minimumDeletions(String s) {
        int preva = 0, prevb = 0;
        for(int i=1;i<=s.length();i++){
            if(s.charAt(i - 1) == 'a'){
                prevb++;
            }else{
                prevb = Math.min(prevb,preva);
                preva++;
            }
        }

        return Math.min(preva,prevb);
    }
}