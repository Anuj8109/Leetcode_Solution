class Solution {
    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        Arrays.sort(hBars);
        Arrays.sort(vBars);

        int maxH = 0;
        int maxV = 0;
        int prev = 0;
        int count = 0;
        for(int index=0;index<hBars.length;index++){
            if(hBars[index] == prev + 1){
                count++;
                prev++;
            }else{
                prev = hBars[index];
                count = 1;
            }
            maxH = Math.max(maxH, count);
        }
        prev = 0;
        count = 0;
        for(int index=0;index<vBars.length;index++){
            if(vBars[index] == prev + 1){
                count++;
                prev++;
            }else{
                prev = vBars[index];
                count = 1;
            }
            maxV = Math.max(maxV, count);
        }

        int size = Math.min(maxV + 1, maxH + 1);
        return size * size;
    }
}