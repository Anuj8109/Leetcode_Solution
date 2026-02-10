class Solution {
    public int longestBalanced(int[] nums) {
        int len = nums.length;

        for(int size=len;size>0;size--){
            HashMap<Integer,Integer> unique = new HashMap<>();
            int countE = 0;
            int countO = 0;
            int index=0;
            while(index<size){
                if(!unique.containsKey(nums[index])){
                    countE += (nums[index] % 2 == 0 ? 1 : 0);
                    countO += (nums[index] % 2 == 1 ? 1 : 0);
                }
                unique.put(nums[index], unique.getOrDefault(nums[index], 0) + 1);
                index++;
            }
            // System.out.println(countE + "  " + countO + " " + unique);
            if(countE == countO) return size;
            for(;index<len;index++){
                int remove = index - size;
                // System.out.println(index + " " + size + " " + unique);
                unique.put(nums[remove], unique.get(nums[remove]) - 1);
                if(unique.get(nums[remove]) == 0){
                    countE -= (nums[remove] % 2 == 0 ? 1 : 0);
                    countO -= (nums[remove] % 2 == 1 ? 1 : 0);
                }
                if(unique.getOrDefault(nums[index],0) == 0){
                    countE += (nums[index] % 2 == 0 ? 1 : 0);
                    countO += (nums[index] % 2 == 1 ? 1 : 0);
                }
                unique.put(nums[index], unique.getOrDefault(nums[index], 0) + 1);
                // System.out.println(countE + "  " + countO + " " + unique + " " + size);
                if(countE == countO){
                    return size;
                }
            }
        }
        return 0;
    }
}