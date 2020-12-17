#include <iostream>
using namespace std;

void reverse(int arr[],int n,int start,int end)
{
    int low=start;
    int high=end;
    while(low<high)
        swap(arr[low++],arr[high--]);
}

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

//method 1
//Time Complexity:- O(n)
//Space complexity:- O(1)
void cyclicRotate1(int arr[],int n)
{
    reverse(arr,n,0,n-1);
    reverse(arr,n,1,n-1);
}

//method 2
//time Complexity:- O(n)
//space Complexity :-O(1)
void cyclicRotateByShifting(int arr[],int n)
{
    int temp=arr[n-1];
    for(int i=n-1;i>0;i--)
        arr[i]=arr[i-1];
    arr[0]=temp;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        //cyclicRotate1(arr,n);
        cyclicRotateByShifting(arr, n);
        display(arr,n);
    }

    return 0;
}
