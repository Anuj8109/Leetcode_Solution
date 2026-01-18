class Solution {
    private boolean isPossible(int[][] grid, int i, int j, int k){
        //Row sum check
        int sum = -1;
        for(int p=i;p<i+k;p++){
            int curr = 0;
            for(int q=j;q<j+k;q++){
                curr += grid[p][q];
            }
            if(sum == -1){
                sum = curr;
            }else if(sum != curr){
                return false;
            }
        }

        for(int q=j;q<j+k;q++){
            int curr = 0;
            for(int p=i;p<i+k;p++){
                curr += grid[p][q];
            }
            if(sum != curr) return false;
        }
        int diag1 = 0;
        int diag2 = 0;
        for(int r=0;r<k;r++){
            diag1 += grid[i + r][j + r];
            diag2 += grid[i + k - 1 - r][j + r];
        }

        if(diag1 != sum || diag2 != sum) return false;
        return true;
    }
    public int largestMagicSquare(int[][] grid) {
        // 50 * 50 * 50 * 50 

        int m = grid.length;
        int n = grid[0].length;
        int maxSide = 1;

        // if(isPossible(grid, 1, 1, 3)){
        //     return 3;
        // }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=maxSide+1;i + k <= m && j + k <= n; k++){
                    if(isPossible(grid, i, j, k)){
                        maxSide = k;
                    }
                }
            }
        }
        return maxSide;
    }
}