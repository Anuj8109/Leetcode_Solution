class Solution {
    public int longestBalanced(String s) {
        int[] freq = new int[26];
        for(int len=s.length();len>1;len--){

            Arrays.fill(freq, 0);

            for(int index=0;index<s.length();index++){
                freq[s.charAt(index) - 'a']++;
                
                if(index - len >= 0){
                    freq[s.charAt(index - len) - 'a']--;
                }
                // int count = freq[s.charAt(index) - 'a'];
                if(index + 1 >= len){
                    boolean isEqual = true;
                    int count = freq[s.charAt(index) - 'a'];
                    // Set<Integer> unique = new HashSet<>();
                    for(int i=0;i<26 && isEqual;i++){
                        if(freq[i] != 0 && count != freq[i]) isEqual = false;
                    }
                    if(isEqual) return len;
                }
            }
        }
        return 1;
    }
}