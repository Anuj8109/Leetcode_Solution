class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int ans = 1;
        int i = 0;
        
        int n = nums.size();
        int mlen = min(nums[0] + 1,n);
        if(nums[0] >= n-1) return 1;
        while(i < n){
            int m = 0;
            int im = 0;
            int j = i + 1;
            
            while(j < mlen){
                if(m + im < nums[j] + j){
                    im = j;
                    m = nums[j];
                }
                j++;
            }
            ans++;
            if(im + m >= n - 1){
                break;
            }
            cout<<im<<" "<<m<<endl;
            i = im;
            mlen = min(m + im + 1,n);
            
        }
        return ans;
    }
};