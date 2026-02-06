class Solution {
    public boolean isPossible(int[] nums, int k, int mid){
        for(int index=0;index+mid-1<nums.length;index++){
            // long mini = ;
            // long maxi = nums[index + mid - 1];
            // System.out.println("TEST " +  maxi + " " + mini + " " + Long.compare(maxi, mini));
            if(Long.compare(nums[index + mid - 1], (long)nums[index] * k) <= 0){
                return true;
            }
        }
        return false;
    }
    public int minRemoval(int[] nums, int k) {
        Arrays.sort(nums);
        int start = 1;
        int end = nums.length;
        int ans = 0;
        while(start <= end){
            int mid = (start + end) >> 1;
            // System.out.println(start + " " + end + " " + mid);
            if(isPossible(nums, k, mid)){
                ans = Math.max(ans, mid);
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        System.out.println(ans);
        return nums.length - ans;
    }
}