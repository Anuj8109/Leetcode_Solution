class Solution {
    public int minCost(int n, int[][] edges) {
        List<List<int[]>> adjList = new ArrayList<>();
        for(int i=0;i<n;i++){
            adjList.add(new ArrayList<>());
        }

        for(int[] edge:edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adjList.get(u).add(new int[]{v,w});
            adjList.get(v).add(new int[]{u,2*w});
        }
        int[] d = new int[n];
        Arrays.fill(d, Integer.MAX_VALUE);

        PriorityQueue<int[]> pq = new PriorityQueue<>((int[] a, int[] b) -> {
            return Integer.compare(a[0], b[0]);
        });
        d[0] = 0;
        pq.add(new int[]{0,0});
        int result = 0;
        int count = 0;
        while(!pq.isEmpty()){
            int[] curr = pq.poll();
            int w = curr[0];
            int i = curr[1];
            if(d[i] < w) continue;
            // result = Math.max(d[i], result);
            // System.out.println()
            count++;
            for(int[] next:adjList.get(i)){
                int weight = w + next[1];
                int index = next[0];
                if(d[index] > weight){
                    d[index] = weight;
                    pq.add(new int[]{weight, index});
                }
            }
        }
        return d[n - 1] == Integer.MAX_VALUE ? -1 : d[n - 1];
    }
}