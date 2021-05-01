#include<iostream>
#include<algorithm>
using namespace std;

//Optimised approach (two pointr)
//Not maintaining order
//time complexity :- O(n)
//space complexity :- O(1)
void moveNegPos(int arr[],int n)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        if(arr[low]>0 && arr[high]>0)
            high--;
        else if(arr[low]<0 && arr[high]<0)
            low++;
        else if(arr[low]<0 && arr[high]>0)
        {
            low++;
            high--;
        }
        else
            swap(arr[low],arr[high]);
    }
}

//Unoptimised approach (Sorting)
//time complexity :- O(nlogn)
//space complexity :- O(1)
//Not maintaining order
void moveNegPosMethod1(int arr[],int n)
{
    sort(arr,arr+n);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    moveNegPos(arr,n);
    //moveNegPosMethod1(arr, n);

    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}

//Optimised approach
//time complexity :- O(n)
//space complexity :- O(n)
//maintaining order
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        vector<int> pos;
        vector<int> neg;
        for(int i=0;i<n;i++)
        {
            int cur=arr[i];
            if(cur<0)
                neg.push_back(cur);
            else
                pos.push_back(cur);
        }
        for(int i=0;i<pos.size();i++)
            arr[i]=pos.at(i);
        for(int i=0;i<neg.size();i++)
            arr[i+pos.size()]=neg.at(i);
    }
};
