class Solution{    
  public:
    //Function to find the maximum money the thief can get.
    
    int fms(int arr[],int dp[],int n,int cur)
    {
        if(cur>=n)
            return 0;
        if(dp[cur]==-1)
            dp[cur]=max(arr[cur]+fms(arr,dp,n,cur+2),fms(arr,dp,n,cur+1));
        return dp[cur];
        
    }
    
    int FindMaxSum(int arr[], int n)
    {
        int dp[n];
        for(int i=0;i<n;i++)
            dp[i]=-1;
        return fms(arr,dp,n,0);
    }
};
