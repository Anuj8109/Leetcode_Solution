class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        Arrays.sort(capacity);
        int total = 0;
        for(int i:apple) total+=i;
        int index = capacity.length - 1;
        while(index >= 0 && total > 0){
            total -= capacity[index--];
            // index--;
        }
        return capacity.length - index - 1;
    }
}