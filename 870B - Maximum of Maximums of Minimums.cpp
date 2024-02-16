/*
Given an array we have to split the array into exactly k segments such that the 
maximum(minimum of subsegment 1 , minimum of subsegment 2 , .... minimum of subsegment k) is maximum.
Lets the break the problem into cases and solve
Case 1 :
    k = 1
    We should consider the whole array, minimum of the whole array(which itself is the subsegment)
    will be the element at position 0 of sorted array.
    Maximum of 1 value will be the value itself as there is no other value to compare with.
Case 2 :
    k = 2
    This is a tricky case. At first glance it is difficult to understand why the ans is max(arr[0],arr[n-1]) basically the first and last element.
    Since we have to split the array into exactly two parts, the first and last element will always be part of different subsegments
    We check the greater value among the two and we split the array such that arr[0] and remaining or arr[n-1] and remaining
    If we could get a lower maximum in other splittings, we avoid those.
    Ex : [12 , 0 , -4 , 10 , -13 , 30 , 14] answer is max (12,14) = 14
    If you split it into parts in any manner the answer remains the same, solve few examples for better understanding.
    Say [12,0,-4,10,-13] [30,14] --> max(-13,14) = 14
    Say [12,0,-4,10] [-13,30,14] --> max(-4,-13) = -13
    Our goal is to maximise, not minimise.
Case 3 :
    k > = 3
    Since our goal is to maximise our answer we can always make sure that there is a subsegment among k subsegments
    such that only the largest element of the array is present in that regardless of its position in the array
    This way the largest element comes out as minimum from its subsegment and when compared with other minimums
    This makes it the maximum.
    Ex : array = [2, -9 , 34  , 10 , -31 , 0 , 12] and k=3 lets say
    We want 34 to be the answer, let subsegment k=1 [2,-9] , k=2 [34] , k=3 [10,-31,0,12]
    maximum of (-9,34,-31) = 34
    We can always achieve this when k>=3 and k<=n
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

    ll n,k;
    cin>>n>>k;
    ll a[n];
    f(0,n)
    cin>>a[i];
    if(k==1){
      sort(a,a+n);
      cout<<a[0]<<endl;
    }
    else if(k>=3){
      sort(a,a+n);
      cout<<a[n-1]<<endl;
    }
    else{ 
      cout<<max(a[0],a[n-1])<<endl;
    }

  return 0;
}
