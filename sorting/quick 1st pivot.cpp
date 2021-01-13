/****************************
*  Developer : joshi08
*  Date  :  12-06-2020
*  Year  :  2020
****************************/

#include <bits/stdc++.h>

#define lli long long int
#define mod 1000000007
#define fi first
#define se second
#define ii pair<lli, lli>
#define mp make_pair
#define endl '\n'
const double PI = 3.141592653589793238460;
lli gcd(lli a, lli b) { if (a == 0) return b; return gcd(b % a, a);}
lli max(lli a, lli b) {if (a > b) return a; else return b;}
lli min(lli a, lli b) {if (a < b) return a; else return b;}
lli power(lli a,lli b) {lli i,p=1; for(i=0;i<b;i++){p*=a;} return p;}

using namespace std;
lli comparison=0;

lli partition(vector<lli> &arr,lli l,lli r)
{
	lli i,j,temp,p;
	i=l;
	
	p = l + ((r-l)/2);
	
	
	temp = arr[l];
	arr[l] = arr[r];
	arr[r] = temp;
	
	
	/*if( (arr[l]>=arr[p] && arr[p]>=arr[r]) || (arr[l]<=arr[p] && arr[p]<=arr[r]) )
	{
		temp = arr[l];
		arr[l] = arr[p];
		arr[p] = temp;
	}
	else
	if( (arr[p]>=arr[r] && arr[r]>=arr[l]) || (arr[l]>=arr[r] && arr[r]>=arr[p]) )
	{
		temp = arr[l];
		arr[l] = arr[r];
		arr[r] = temp;
	}*/
	
	for(j=l+1;j<=r;j++)
	{
		if(arr[l]>=arr[j])
		{
			temp = arr[i+1];
			arr[i+1] = arr[j];
			arr[j] = temp;
			i++;
		}
	}
	temp = arr[i];
	arr[i] = arr[l];
	arr[l] = temp;
	comparison += (r-l);
	
	/*for(j=r-1;j>=l;j--)
	{
		if(arr[r]<arr[j])
		{
			temp = arr[i-1];
			arr[i-1] = arr[j];
			arr[j] = temp;
			i--;
		}
	}
	
	temp = arr[i];
	arr[i] = arr[r];
	arr[r] = temp;
	comparison += (r-l);*/
	
	return i;
}

void quicksort(vector<lli> &arr,lli l,lli r)
{
	if(l<r)
	{
		lli p = partition(arr,l,r);
		//cout<<l<<" "<<p<<" "<<r<<endl;
		quicksort(arr,l,p-1);
		quicksort(arr,p+1,r);
	}
}


int main()
{
    ios::sync_with_stdio(false);

	lli n,i,k;
	cin>>n;
	vector<lli> arr;
	
	for(i=0;i<n;i++)
	{
		cin>>k;
		arr.push_back(k);
	}
	
	quicksort(arr,0,n-1);
	
	cout<<endl;
	cout<<comparison;
    return 0;
}



//162085

//170025
//164123

//138382
