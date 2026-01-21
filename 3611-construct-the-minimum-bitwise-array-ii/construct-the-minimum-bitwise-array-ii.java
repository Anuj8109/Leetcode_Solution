class Solution {
    public int[] minBitwiseArray(List<Integer> nums) {
        // for even number -> not possible to form ans -> -1
        //. 101111 -> 100111
        // 1011 -> 1001
        // 11111 -> 01111

        int[] result = new int[nums.size()];
        for(int index=0;index<nums.size();index++){
            if(nums.get(index) % 2 == 0) result[index] = -1;
            else{
                int bit = 0;
                int curr = nums.get(index);
                while((curr & 1 << bit) > 0){
                    bit++;
                }
                bit--;
                // System.out.println(index+ " " + bit);
                result[index] = (curr & ~(1 << bit));
                // int half = nums.get(index)/2;
                // if((half | (half + 1)) == nums.get(index)){
                //     result[index] = half;
                // }else{
                //     int curr = nums.get(index) - 1;
                //     while((curr | (curr + 1)) == nums.get(index)){
                //         curr--;
                //     }
                //     result[index] = curr + 1;
                // }
            }
        }
        return result;
    }
}