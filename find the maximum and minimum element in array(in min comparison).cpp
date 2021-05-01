#include<iostream>
#include<utility>
using namespace std;

//Method 1
pair<int, int> findMaxMinUnoptimised(int arr[], int n)
{
    pair<int,int> res;
    if(n==1)
        res=make_pair(arr[0],arr[0]);
    else if(n==2)
        res=arr[0]>arr[1]?make_pair(arr[0],arr[1]):make_pair(arr[1],arr[0]);
    else
    {
        res=arr[0]>arr[1]?make_pair(arr[0],arr[1]):make_pair(arr[1],arr[0]);
        for(int i=2;i<n;i++)
        {
            if(arr[i]<res.second)
                res.second=arr[i];
            if (arr[i]>res.first)
                res.first=arr[i];
        }
    }
    return res;
}

//Method 2
pair<int,int> findMaxMinOptimised(int arr[],int n)
{
    pair<int,int> res;
    if (n==1)
        res=make_pair(arr[0],arr[0]);
    else if(n==2)
        res=arr[0]>arr[1]?make_pair(arr[0],arr[1]):make_pair(arr[1],arr[0]);
    else
    {
        int start;
        if(n%2==0)
        {
            res=arr[0]>arr[1]?make_pair(arr[0],arr[1]):make_pair(arr[1],arr[0]);
            start=2;
        }
        else
        {
            res=make_pair(arr[0],arr[0]);
            start=1;
        }
        for(int i=start;i<n;i+=2)
        {
            int max=arr[i]>arr[i+1]?arr[i]:arr[i+1];
            int min=arr[i]<arr[i+1]?arr[i]:arr[i+1];
            if(max>res.first)
                res.first=max;
            if(min<res.second)
                res.second=min;
        }
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    pair<int,int> res=findMaxMinOptimised(arr,n);
    cout<<"Max element: "<<res.first<<endl;
    cout<<"Min element: "<<res.second<<endl;

    return 0;
}
