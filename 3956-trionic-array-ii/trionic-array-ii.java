class Solution {
    public int incr(int[] nums, int start){
        int len = nums.length;
        while(start + 1 < len && nums[start] < nums[start + 1]){
            start++;
        }
        return start;
    }

     public int decr(int[] nums, int start){
        int len = nums.length;
        while(start + 1 < len && nums[start] > nums[start + 1]){
            start++;
        }
        return start;
    }

    
    public long maxSumTrionic(int[] nums) {
        int len = nums.length;
        int start = 0;
        int i1 = incr(nums, start); // ending for first subarray 
        // int s1 = i1;
        // int d = decr(nums, i1);
        // int i2 = incr(nums, d);
        // if(i1 == d || d == i2) return 

        long result = Long.MIN_VALUE >> 1;

        while(start < len){
            int d = decr(nums, i1); // ending for second subArray
            if(i1 == d){
                start = d + 1;
                i1 = incr(nums, start);
                continue;
            }
            int i2 = incr(nums, d); //ending for last subArray
            if(i2 == d){
                start = i2 + 1;
                i1 = incr(nums, start);
                continue;
            }
            
            // first subaarry -> start - i1 
            // second subarry -> d - i1
            // third subarry -> i2 - d
            long s1 = Long.MIN_VALUE >> 1;
            long s2 = Long.MIN_VALUE >> 1;
            long s3 = Long.MIN_VALUE >> 1;
            int index = i1;
            long curr = nums[index--];
            while(index >= start){
                curr += nums[index--];
                s1 = Math.max(s1, curr);
            }

            index = i1 + 1;
            curr = 0;
            while(index <= d){
                curr += nums[index++];
                // s2 = Math.max(s2, curr);
            }
            s2 = curr;
            index = d + 1;
            curr = 0;
            while(index <= i2){
                curr += nums[index++];
                s3 = Math.max(s3, curr);
            }
            // System.out.println(start + " " + i1 + " " + d + " " + i2);
            // System.out.println(s1 + " " + s2 + " " + s3);
            result = Math.max(result, s1 + s2 + s3);
            start = d;
            i1 = i2;
        }
        return result;
    }
}