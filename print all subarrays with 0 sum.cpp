class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        unordered_map<ll,ll> freq;
        freq.insert({0,1});
        ll count=0;
        ll pre=0;
        for(ll i=0;i<n;i++)
        {
            pre+=arr[i];
            freq[pre]++;
        }
        for(auto x: freq)
        {
            int y=x.second;
            count+=((y*(y-1))/2);
        }
        return count;
    }
};
