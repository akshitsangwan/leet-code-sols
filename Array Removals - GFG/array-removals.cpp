//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int removals(vector<int>& arr, int k){
        if(arr.size() == 1)  
            return 0;
      
        sort(arr.begin(),arr.end());
        vector<int> ans;
        
        for(int i = 0 ;i < arr.size()-1; i++)
            for(int j = arr.size()-1; j > i; j--)
                if((arr[j] - arr[i]) <= k)
                {
                    ans.push_back(arr.size()- (j-i+1));
                    break;
                }
        
        int me = 1;
        if(ans.size())me = *min_element(ans.begin(),ans.end());
        return me;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends