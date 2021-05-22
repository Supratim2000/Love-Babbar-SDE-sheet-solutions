//Approach 1(Brute force)
//Time O(n^3) Space(1)
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        int max_sum=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int sum=0;
                for(int x=i;x<=j;x++)
                    sum+=arr[x];
                if(sum>max_sum)
                    max_sum=sum;
            }
        }
        return max_sum;
    }
};

//Approach 3(Kadane's Algorithm)
// Time O(n) Space O(1)
----------------------------------
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        long long sum=0;
        long long maxSum=INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum<0)
                sum=0;
            if(sum>maxSum)
                maxSum=sum;
        }
        return maxSum;
    }
};

//Kadane's algorithm handling all negative array elements
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int freq=0;
        if(n==1)
            return nums.at(0);
        int max_elmt=INT_MIN;
        int sum=0;
        int maxSum=INT_MIN;
        
        for(auto x:nums)
        {
            sum+=x;
            max_elmt=max(x,max_elmt);
            if(sum<0)
            {
                sum=0;
                freq++;
            }
            if(maxSum<sum)
                maxSum=sum;
        }
        if(freq==n)
            return max_elmt;
        return maxSum;
    }
};
