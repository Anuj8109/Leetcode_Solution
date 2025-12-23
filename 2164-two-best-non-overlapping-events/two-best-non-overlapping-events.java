class Solution {
    public int maxTwoEvents(int[][] events) {
        Comparator<int[]> comp = (a,b) -> {
            if(a[1] == b[1]){
                if(a[0] == b[0]) return Integer.compare(b[2],a[2]);
                else return Integer.compare(b[0],a[0]);
            }
            return Integer.compare(a[1], b[1]);
        };
        Arrays.sort(events,comp);
        TreeMap<Integer,Integer> map = new TreeMap<>();
        map.put(0,0);
        int ans = 0;
        for(int[] event:events){
            int value = event[2];
            int start = event[0];
            int end = event[1];
            Integer prevTime = map.floorKey(start - 1);
            int totalValue = map.get(prevTime) + value;
            // totalValue = Math.max(totalValue, map.get(map.floorKey(end)));
            int currMax = Math.max(value, map.get(map.floorKey(end)));
            // System.out.println(map.floorKey(end) + " " + map.get(map.floorKey(end)));
            ans = Math.max(totalValue, ans);
            map.put(end,currMax);
            // System.out.println(start + " " + end + " " + value + " " + totalValue + " " + currMax);
        }
        return ans;
    }
}