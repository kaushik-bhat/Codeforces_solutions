/*
This is very simple combinations problem you just have to be careful to so that there's no everflow.
The problem is basically out of n things you have to output the number ways to select groups of size 5 + groups of size 6 + groups of size 7
We can implement the nCr function, but there are chances of getting the wrong answer due to integer overflow.
Since we know the r values and it is small let us manually write the reduced formulas to calculate nC5 , nC6 , nC7 and return the sum of these three
Let us understand nC5 case which is enough to understand the remaining cases
nC5 = n! / [(n-r)! * r!] -->  n / 1 * (n-1) / 2 * (n-2) / 3 * (n-3) / 4 * (n- 4)/ 5
This way the value i doesnt grow very big and also we wont get wrong answer because of rounding of numbers during division 
Because, n/1 will be n , n*(n-1)/2 will always be a whole number cause either n or n-1 will be even, similarly n*(n-1)/2*(n-2)/3 atleast one of n,n-1,n-2 will be divisible by 3, so on and so forth

I hope this was enough for you understand the solution.
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
    ll ans5,ans6,ans7;
    ans5 = n / 1 * (n-1) / 2 * (n-2) / 3 * (n-3) / 4 * (n- 4)/ 5;
    ans6 = n / 1 * (n-1) / 2 * (n-2) / 3 * (n-3) / 4 * (n-4)/ 5 * (n-5) /6;
    ans7 = n / 1 * (n-1) / 2 * (n-2) / 3 * (n-3) / 4 * (n-4)/ 5* (n-5) /6 * (n-6) / 7;
    cout<<ans5+ans6+ans7<<endl;
}
