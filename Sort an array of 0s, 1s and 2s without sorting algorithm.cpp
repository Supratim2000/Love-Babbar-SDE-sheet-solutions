
//Method 1
class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        int count=0;
        int freq[3]={0};
        for(int i=0;i<n;i++)
            freq[arr[i]]++;
        for(int i=0;i<3;i++)
        {
            while(freq[i])
            {
                arr[count++]=i;
                freq[i]--;
            }
        }
    }
};

//Method 2(Dutch national flag algorithm)
class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        int i=0;
        int j=n-1;
        int mid=0;
        while(mid<n && mid<=j)
        {
            if(arr[mid]==0)
                swap(arr[i++],arr[mid++]);
            else if(arr[mid]==1)
                mid++;
            else
                swap(arr[j--],arr[mid]);
        }
    }
};
