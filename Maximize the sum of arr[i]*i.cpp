class Solution{
    public:
    int Maximize(int a[],int n)
    {
        sort(a,a+n);
        int mod=1000000007;
        long long ans=0;
        for(long long i=0;i<n;i++)
            ans+=(a[i]*i);
        return ans%mod;
    }
};
