#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main()
{
	ll n;
	cin>>n;
	vector<ll> arr;
	vector<ll> pre(n,0);
	for(ll i=0;i<n;i++)
	{
		ll tp;
		cin>>tp;
		arr.push_back(tp);
	}
	sort(arr.begin(),arr.end());
	for(ll i=0;i<n;i++)
	{
		if(i==0)
			pre[0]=arr[0];
		else
			pre[i]=arr[i]+pre[i-1];
	}

	ll q;
	cin>>q;
	while(q--)
	{
		ll x;
		cin>>x;
		ll ans=0;
		ll l=0;
		ll h=n-1;
		while(l<=h)
		{
			ll m=l+(h-l)/2;
			if(arr[m]<=x)
			{
				ans=m+1;
				l=m+1;
			}
			else
				h=m-1;
		}
		
		if(ans==0)
			cout<<0<<" "<<0<<endl;
		else
			cout<<ans<<" "<<pre[ans-1]<<endl;
	}
	return 0;
}
