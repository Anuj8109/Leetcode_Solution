class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size();
        int j = n - 1;
        int i = 0;
        int ans = 0;
        while(j >= i){
            if(people[j] + people[i] <= limit){
                i++;
            }
            j--;
            ans++;
        }
        return ans;
    }
};