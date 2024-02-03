/*
This is one of those problems where many solutions exist, we will now try to understand one of them.
At first when i looked at this problem i thought just print n prime numbers starting from 2 till the Nth prime number.
But it is just unnecessary calculations i felt.
For any given number n, the next number divisible by n will be 2*n therefore all numbers between n and 2*n will not be divisible by n
And also the numbers between n and 2*n including n and not 2*n is n
I guess we found our answer, just print all numbers starting from n and upto 2*n - 1.
Also as 1<=n<=100000 or 10^5 , 2*n will always be <=10000000 or 10^7.

Beautiful!
*/
#include <bits/stdc++.h>
using namespace std;

#define f(a,b) for(ll i=a;i<b;i++)
#define ll long long int
#define pb(n) push_back(n)
#define endl "\n"

const ll mod = 10e9+7;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" ,stdin);
    freopen("output.txt", "w" ,stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    ll n;
    cin>>n;
    f(n,2*n)
    cout<<i<<" ";
    return 0;

}
