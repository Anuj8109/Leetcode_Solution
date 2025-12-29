class Solution {
    HashMap<String, Boolean> dp;
    public boolean isValid(String bottom, HashMap<String, int[]> freqMap, int index, StringBuilder sb){
        if(index == bottom.length() - 1){
            if(sb.length() == 1) return true;
            StringBuilder next = new StringBuilder();
            return isValid(sb.toString(), freqMap, 0, next);
        }
        if(dp.containsKey(bottom)) return dp.get(bottom);

        String curr = bottom.substring(index, index + 2);
        if(!freqMap.containsKey(curr)) return false;
        int[] tops = freqMap.get(curr);
        for(int i=0;i<6;i++){
            if(tops[i] == 0) continue;
            sb.append((char)('A' + i));
            if(isValid(bottom,freqMap, index + 1, sb)){
                if(index == 0) dp.put(bottom, true);
                return true;
            }
            sb.deleteCharAt(sb.length() - 1);
        }
        if(index == 0) dp.put(bottom, false);
        return false;

    }
    public boolean pyramidTransition(String bottom, List<String> allowed) {
        HashMap<String, int[]> freqMap = new HashMap<>();
        for(String str:allowed){
            String block = str.substring(0,2);
            char next = str.charAt(2);
            if(!freqMap.containsKey(block)){
                int[] count = new int[6];
                freqMap.put(block, count);
            }
            // System.out.println(freqMap.get(block)[next - 'A']);
            freqMap.get(block)[next - 'A']++;
            // System.out.println(freqMap.get(block)[next - 'A']);
        }
        dp = new HashMap<>();
        StringBuilder sb = new StringBuilder();
        return isValid(bottom, freqMap, 0, sb);
    }
}