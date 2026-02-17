class Solution {
    public int maxFreeTime(int eventTime, int k, int[] startTime, int[] endTime) {
        // Queue -> end time and meeting time
        // if queue size is less than K then we move to forward meeting
        // else remove first meeting and require time from count 

        int n = startTime.length;
        // int[][] meetings = new int[n][2];

        // for(int index=0;index<n;index++){
        //     meetings[index][0] = startTime[index];
        //     meetings[index][1] = endTime[index];
        // }
        // Comparator<int[]> comp = (int[] a, int[] b) -> {

        // };
        // Arrays.sort(meeting, )
        Queue<int[]> rescheduleMeet = new LinkedList<>();

        int result = startTime[0];
        result = Math.max(result, eventTime - endTime[n - 1]);
        int sum = 0;
        
        for(int index=0;index<n;index++){
            int timeTaken = endTime[index] - startTime[index];
            rescheduleMeet.add(new int[]{endTime[index], timeTaken});
            sum += timeTaken;
            int endingLastMeet = sum;
            if(rescheduleMeet.size() > k){
                int[] removeMeeting = rescheduleMeet.poll();
                sum -= removeMeeting[1];
                endingLastMeet = removeMeeting[0] + sum;
            }
            int startNextMeet = (index + 1) < n ? startTime[index + 1] : eventTime;
            result = Math.max(result, startNextMeet -endingLastMeet);
        }
        return result;
    }
}