class Solution {
public:
    long long minimumTime(vector<int>& time, int total) {
        long long ans = 0;
        long long left = 0;
        long long right = (long long)total * 1e7;
        while(left <= right){
            long long mid = (left + right)/2;
            long long count = 0;
            for(auto t:time){
                count += mid/t;
                if(count >= total) break;
            }
            if(count >= total){
                ans = mid;
                right = mid - 1;
            }else left = mid + 1;
        }
        return ans;
    }
};