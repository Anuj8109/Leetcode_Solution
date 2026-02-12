class Solution {
    public int longestBalanced(String s) {
        for(int len=s.length();len>1;len--){

            int[] freq = new int[26];

            for(int index=0;index<s.length();index++){
                freq[s.charAt(index) - 'a']++;
                
                if(index - len >= 0){
                    freq[s.charAt(index - len) - 'a']--;
                }
                // int count = freq[s.charAt(index) - 'a'];
                if(index + 1 >= len){
                    // boolean isEqual = true;
                    Set<Integer> unique = new HashSet<>();
                    for(int i=0;i<26;i++){
                        if(freq[i] != 0) unique.add(freq[i]);
                    }
                    if(unique.size() == 1) return len;
                }
            }
        }
        return 1;
    }
}