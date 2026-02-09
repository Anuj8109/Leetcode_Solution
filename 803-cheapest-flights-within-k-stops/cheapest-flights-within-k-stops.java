class Solution {
        public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        Map<Integer, Map<Integer, Integer>> prices = new HashMap<>();
        for (int[] f : flights) {
            if (!prices.containsKey(f[0])) prices.put(f[0], new HashMap<>());
            prices.get(f[0]).put(f[1], f[2]);
        }
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> (Integer.compare(a[0], b[0])));
        pq.add(new int[] {0, src, k + 1});
        Integer[][] dp = new Integer[k + 2][n + 1];
        dp[k + 1][src] = 0;
        while (!pq.isEmpty()) {
            int[] top = pq.remove();
            int price = top[0];
            int city = top[1];
            int stops = top[2];
            if(dp[stops][city] < price) continue;
            // visited[stops][city] = true;
            if (city == dst) return price;
            if (stops > 0) {
                Map<Integer, Integer> adj = prices.getOrDefault(city, new HashMap<>());
                for (int a : adj.keySet()) {
                    if(dp[stops - 1][a] == null ||
                     dp[stops - 1][a] > price + adj.get(a)) {
                        dp[stops - 1][a] = price + adj.get(a);
                        pq.add(new int[] {dp[stops - 1][a], a, stops - 1});
                    }
                }
            }
        }
        return -1;
    }
    // public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        
    // }
}