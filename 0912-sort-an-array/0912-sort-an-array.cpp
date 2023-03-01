class Solution {
public:
    void merge(vector<int> &arr,int left,int mid,int right){
        vector<int> l(mid - left + 1);
        vector<int> r(right - mid);
        int j=0;
        for(int i=left;i<=mid;i++){
            l[j++] = arr[i];
        }
        j = 0;
        for(int i=mid + 1;i<=right;i++){
            r[j++] = arr[i];
        }
        
        int i=0,k=left;
        j=0;
        while(i < mid - left + 1 && j < right - mid){
            if(l[i] < r[j]) arr[k++] = l[i++];
            else arr[k++] = r[j++];
        }
        while(i < mid - left + 1){
            arr[k++] = l[i++];
        }
        while(j < right - mid){
            arr[k++] = r[j++];
        }
    }
    void mergeSort(vector<int> &arr,int left,int right){
        if(left >= right) return ;
        
        int mid = (left + right)/2;
        
        mergeSort(arr,left,mid);
        mergeSort(arr,mid + 1,right);
        merge(arr,left,mid,right);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size() - 1);
        return nums;
    }
};