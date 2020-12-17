#include<iostream>
#include<algorithm>
using namespace std;

//Optimised approach (two pointr)
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
