/*
First let us understand what is a permutation.
say n=5, then permutation p is a set of numbers p1,p2,p3,p4,p5 [p1,p2,...p(n-2),p(n-1),p(n)] where each p(i) that belongs to the set is a
distinct positive integer and doesn't exceed. Which is the formal definition but in layman's terms it is the set of numbers ranging from 1 to the given n.
Now let us understand logically why the below code works.
We take the input of n numbers and store it in an array of size n.
We sort the array.
Now we know that for any permutation [p1,p2,...p(n-2),p(n-1),p(n)] p1 will be 1 p2 will be 2 so on and so forth where p(n) is n.
Therefore in the sorted array at every position we just check the no of operations needed to be performed on the a[i[ element to make it equal to (i+1) because remember arrays are 0 indexed.
Ex: n=6 and the array is 0 8 17 -10 3 5
after sorting the array is
-10 0 3 5 8 17 ->sorted array
[1  2 3 4 5 6] -> our goal
clearly it is ideal to change -10 to 1 than any other number say 2,3,4,5,6

Hope this helped you understand the solution logically.
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
    ll a[n];
    ll ans=0;
    f(0,n){
      cin>>a[i];
    }
    sort(a,a+n);
    f(0,n){
      ans+=(abs(a[i]-(i+1)));
    }
    cout<<ans<<endl;

    return 0;

}
