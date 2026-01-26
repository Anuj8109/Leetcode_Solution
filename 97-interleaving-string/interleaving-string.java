class Solution {
    Boolean[][] dp;
    public boolean helper(String s1, String s2, String s3, int i, int j, int k){
        
        if(s3.length() == k) return true;
        if(dp[i][j] != null) return dp[i][j];
        boolean result = false;
        //Skip s1 string selection
        if(j < s2.length() && s2.charAt(j) == s3.charAt(k)) 
            result = helper(s1,s2, s3, i, j + 1, k + 1);

        int i1 = i, k1 = k;
        while(i1 < s1.length() && k1 < s3.length() && !result){
            if(s1.charAt(i1) == s3.charAt(k1)){
                result = helper(s1,s2,s3, i1 + 1, j, k1 + 1);
            }else break;
            i1++;
            k1++;
        }
        // for(int temp=i;temp<s1.length() && !result;temp++){
        //     if(s1.charAt(temp) == s3.charAt(k + temp - i))
        //         result = helper(s1, s2, s3, temp, j, k + 1);
        // }
        return dp[i][j] = result;
        
        // if(s3.length() == k) return true;
        // if(dp[i][j] != -1) return dp[i][j] == 1;
        // boolean result = false;
        // if(i < s1.length() && s1.charAt(i) == s3.charAt(k)){
        //     result |= helper(s1, s2, s3, i + 1, j, k + 1, dp);
        // }
        // if(result) return result;

        // if(j < s2.length() && s2.charAt(j) == s3.charAt(k)){
        //     result = helper(s1, s2, s3, i, j + 1, k + 1, dp);
        // }
        // dp[i][j] = (result ? 1 : 0);
        // return result;
    }
    public boolean isInterleave(String s1, String s2, String s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        dp = new Boolean[s1.length() + 1][s2.length() + 1];
        // for(int i=0;i<=s1.length();i++){
        //     // Arrays.fill(dp[i], false);
        // }
        return helper(s1, s2, s3, 0, 0, 0);
    }
}