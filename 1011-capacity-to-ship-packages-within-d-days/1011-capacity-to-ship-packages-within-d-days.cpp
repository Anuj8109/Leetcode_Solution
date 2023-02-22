class Solution {
public:
    int shipWithinDays(vector<int>& wei, int k) {
        long ans = INT_MAX;
        int sum = 0;
        for(auto i:wei){
            sum += i;
        }
        int s = 0;
        int e = sum;
        
        while(s <= e){
            long mid = (s + e)/2;
            int count = 0;
            int curr = 0;
            bool posi = true;
            for(auto i:wei){
                // curr += i;
                if(i > mid){
                    posi = false;
                    break;
                }else if(i + curr > mid){
                    count++;
                    curr = i;
                }else{
                    curr += i;
                }
            }
            count++;
            if(posi){
                // cout<<count<<" "<<mid<<endl;
                if(count <= k){
                    ans = min(ans,mid);
                    e = mid - 1;
                }
                else s = mid + 1;
            }else{
                s = mid + 1;
            }
        }
        return ans;
    }
};