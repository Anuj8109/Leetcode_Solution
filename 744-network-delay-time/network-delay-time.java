class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        List<List<Pair<Integer,Integer>>> adjList = new ArrayList<>();
        for(int i=0;i<=n;i++){
            adjList.add(new ArrayList<>());
        }

        for(int[] time:times){
            adjList.get(time[0]).add(new Pair<>(time[1], time[2]));
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        int[] delays = new int[n + 1];
        Arrays.fill(delays, Integer.MAX_VALUE>>1);
        pq.add(new int[]{0, k});
        int minimum = Integer.MIN_VALUE;
        delays[k] = 0;
        int count  = n;
        while(!pq.isEmpty()){
            int[] curr = pq.poll();
            int delay = curr[0];
            int index = curr[1];
            // System.out.println(delay + " " + index + " " + delays[index]);
            if(delays[index] < delay) continue;
            minimum = Math.max(delays[index], minimum);
            count--;
            // delays[index] = delay;
            for(Pair<Integer,Integer> p:adjList.get(index)){
                if((delays[p.getKey()] > delay + p.getValue())){
                        pq.add(new int[]{delay + p.getValue(), p.getKey()});
                        delays[p.getKey()] = delay + p.getValue();
                        // System.out.println(p.getKey());
                    }
                    
            }
        }
        // for(int i=1;i<=n;i++){
        //     if(delays[i] == Integer.MAX_VALUE>>1){
        //         return -1;
        //     }
        //     if(k == i) continue;
        //     minimum = Math.max(minimum, delays[i]);
        // }
        return count > 0 ? -1 : minimum;
    }
}