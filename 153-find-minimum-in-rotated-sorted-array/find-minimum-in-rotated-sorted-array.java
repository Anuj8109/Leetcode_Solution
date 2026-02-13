class Solution {
    public int findMin(int[] nums) {
        
        int start = 0,end = nums.length - 1;
        //if(nums[start] > nums[end]) return nums[end];
        while (start < end) {
            //System.out.println(start + " " + end);
            int mid = (start + end)/2;
            if(nums[mid] < nums[end]) end = mid;
            else start = mid + 1;
            // if(nums[start] < nums[end]) return nums[start];
            // if(nums[mid] < nums[end]) end = mid;
            // else if(nums[mid] >= nums[end]) start = mid + 1;
        }
        return nums[start];
        
    }
}