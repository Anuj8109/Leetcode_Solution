//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    vector<int> merge2attay(vector<int> a,vector<int> b){
        int i = 0, j = 0, k = 0;
        vector<int> ans(a.size() + b.size());
        while (i<a.size() && j <b.size())
        {
            if (a[i] < b[j])
                ans[k++] = a[i++];
            else
                ans[k++] = b[j++];
        }
        while (i < a.size())
            ans[k++] = a[i++];
        while (j < b.size())
            ans[k++] = b[j++];
        return ans;
    }
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        int n = arr.size();
        while(n > 1){
            for(int i=1;i<n;i+=2){
                arr[i/2] = merge2attay(arr[i-1],arr[i]);
            }
            if(n & 1){
                arr[n/2] = arr[n-1];
                n = n/2 + 1;
            }else n = n/2;
            // cout<<n<<endl;
        }
        return arr[0];
        //code here
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends