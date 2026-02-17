class Solution {
    public int maxFreeTime(int eventTime, int k, int[] startTime, int[] endTime) {
        // Queue -> end time and meeting time
        // if queue size is less than K then we move to forward meeting
        // else remove first meeting and require time from count 

        int n = startTime.length;
        // Queue<int[]> rescheduleMeet = new LinkedList<>();

        int result = startTime[0];
        result = Math.max(result, eventTime - endTime[n - 1]);
        int sum = 0;
        
        for(int index=0;index<n;index++){
            int timeTaken = endTime[index] - startTime[index];
            // rescheduleMeet.add(new int[]{endTime[index], timeTaken});
            sum += timeTaken;
            int endingLastMeet = sum;
            if(index >= k){
                // int[] removeMeeting = rescheduleMeet.poll();
                // int 
                sum -= (endTime[index - k] - startTime[index - k]);
                endingLastMeet = endTime[index - k] + sum;
            }
            int startNextMeet = (index + 1) < n ? startTime[index + 1] : eventTime;
            result = Math.max(result, startNextMeet - endingLastMeet);
        }
        return result;
    }
}