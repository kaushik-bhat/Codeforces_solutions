/*
Another easy problem?
Firstly let us sort the given array this helps in comparing values in array with respect to the x we are going to print and also the index help us with respect to k condition.
Remember the x we output should be in the range [1 , 10^9] inclusive it is.
Let us break the problem down into cases
Case 1 :
    k==n
    Meaning we need to print x value such that all the values in the array <= x , we can just print the last element in the sorted array or any number greater than that.
Case 2 :
    k==0
    Meaning we need to print a value of x such that 0 elements in the array are <= x, basically every number in the array should be strictly greater
    Slightly tricky, lets observe two cases
    Case 2.1 :
        If the smallest number in the array arr[0] is 1 then we can never output any value in the interval [1,10^9] because arr[0]=1 will always be <= to any number in that range.
        Therefore we print -1
    Case 2.2 :
         If the smallest number in the array arr[0] is greater than 1 then we can always print 1 which will satisfy the condition that 0 elemetns are <= 1.
Case 3 :
    0 < k < n
    If arr[k] == arr[k-1] that means we can never print a value x such that exactly k elements are <= x
    Because arr[0] to arr[k-1] will have exactly k elements and we can print x such that x=arr[k-1] because all the elements will be <= x in a sorted array.
    But if arr[k]=arr[k-1] that means if we print arr[k-1] as our answer we will break the exactly k elements condition as one more element now is <= arr[k-1]
    So we print -1
    else 
    we print arr[k-1] the kth element or element at index k-1
*/
#include <bits/stdc++.h>
using namespace std;

#define f(a,b) for(ll i=a;i<b;i++)
#define ll long long int
#define pb(n) push_back(n)
#define endl "\n"

const ll mod = 1e9+7;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" ,stdin);
    freopen("output.txt", "w" ,stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    ll n,k;
    cin>>n>>k;
    ll a[n];
    f(0,n)
    cin>>a[i];
    sort(a,a+n);
    if(k==n){
      cout<<a[n-1]<<endl;
    }
    else if(k==0){
      if(a[0]==1)
        cout<<"-1"<<endl;
      else
        cout<<1<<endl;
    }
    else{
      if(a[k-1]==a[k])
        cout<<"-1"<<endl;
      else
        cout<<a[k-1]<<endl;
    }

    return 0;

}
