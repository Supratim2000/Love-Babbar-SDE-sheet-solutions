class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        vector<long long int> pdt(n,1);
        if(n==1)
            return pdt;
        long long int suf[n];
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
            suf[i]=nums[i]*suf[i+1];
        pdt[0]=suf[1];
        long long int lPdt=nums[0];
        for(int i=1;i<n-1;lPdt*=nums[i],i++)
            pdt[i]=lPdt*suf[i+1];
        pdt[n-1]=lPdt;
        return pdt;
    }
};
