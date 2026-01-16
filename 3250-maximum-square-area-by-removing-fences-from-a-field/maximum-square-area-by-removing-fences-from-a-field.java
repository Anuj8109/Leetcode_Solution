class Solution {
    private long area(int side){
        long area = ((long) side) * side;
        // long mod = 1_000_000_000 + 7;
        return area;
    }
    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        Arrays.sort(hFences);
        Arrays.sort(vFences);
        int hSize = hFences.length;
        int lSize = vFences.length;
        HashSet<Integer> sideLen = new HashSet<>();
        sideLen.add(m - 1);
        for(int i=0;i<hSize;i++){
            int side1 = hFences[i] - 1;
            int side2 = m - hFences[i];
            sideLen.add(side1);
            sideLen.add(side2);
        }

        // sideLen.add(hFences[0] - 1);
        // sideLen.add(m - hFences[hSize - 1]);
        for(int i=0;i<hSize;i++){
            for(int j=i+1;j<hSize;j++){
                int side = hFences[j] - hFences[i];
                sideLen.add(side);
            }
        }

        // for(int index=1;index<hSize;index++){
        //     sideLen.add(hFences[index] - hFences[index-1]);
        // }

        long maxArea = 0;
        for(int i=0;i<lSize;i++){
            for(int j=i+1;j<lSize;j++){
                int side = vFences[j] - vFences[i];
                if(sideLen.contains(side)){
                    maxArea = Math.max(maxArea, area(side));
                }   
            }
        }
        // System.out.println(sideLen);
        if(sideLen.contains(n - 1)){
            maxArea = Math.max(maxArea, area(n - 1));
        }
        for(int i=0;i<lSize;i++){
            int side1 = vFences[i] - 1;
            int side2 = n - vFences[i];
            if(sideLen.contains(side1)){
                // long curr = (long) (side1 * side1);
                maxArea = Math.max(maxArea, area(side1));
            }

            if(sideLen.contains(side2)){
                // long curr = (long) (side2 * side2);
                maxArea = Math.max(maxArea, area(side2));
            }
        }
        long mod = 1_000_000_000 + 7;
        return maxArea == 0 ? -1 : (int)(maxArea % mod);
    }
}