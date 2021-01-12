/****************************
*  Developer : joshi08
*  Date  :  12-01-2021
*  Year  :  2021
****************************/

#include <bits/stdc++.h>
#include <ctime> 

//For Naive Algorithm
/*#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")*/
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds; 

//#define ordered_set tree<int, null_type,less<int> , rb_tree_tag,tree_order_statistics_node_update> 
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;
#define lli long long int
#define mod 1000000007
#define ii pair<lli, lli>
#define mp make_pair
#define endl '\n'
const double PI = 3.141592653589793238460;
lli gcd(lli a, lli b) { if (a == 0) return b; return gcd(b % a, a);}
lli max(lli a, lli b) {if (a > b) return a; else return b;}
lli min(lli a, lli b) {if (a < b) return a; else return b;}
lli power(lli a, lli n){ lli res = 1; while(n){ if(n%2==0){ a *= a; n /= 2; } else{ res *= a; n--; } } return res; }

void random_time() {
	time_t now = time(0);

   cout << "Number of sec since January 1,1970 is:: " << now << endl;

   tm *ltm = localtime(&now);

   
   
   lli p = (ltm->tm_sec * 56) + ltm->tm_min + ltm->tm_hour;
   p = p%ltm->tm_sec;
   cout<<endl<<p;
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	random_time();

    return 0;
}

