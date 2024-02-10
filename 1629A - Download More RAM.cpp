/*
We have to understand that the more we increase our k value the more RAM we can achieve finally.
So we have to sort the values of array 'a' in ascending order then start utilising them, because every time our k is increased
Note while sorting dont mix the values of array 'a' and 'b', each a(i) has a specific b(i) associated with it
You can achieve this in many different ways i have used brute force so that it is easier to understand
Once the sorting is done we just have to iterate through the array 'a' values
If a(i) > k we break since it is a sorted array we will never encounter a value < a(i) value
Else we keep increasing our already available RAM by b(i)

:)
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
    
    ll t;
    cin>>t;
    while(t--)
    {
      ll n,k,temp;
      cin>>n>>k;
      ll a[n],b[n];
      f(0,n)
      cin>>a[i];
      f(0,n)
      cin>>b[i];
      
      f(0,n)
      {
        f(0,n-1)
        {
          if(a[i]>a[i+1])
          {
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
            temp=b[i];
            b[i]=b[i+1];
            b[i+1]=temp;
          }
        }
      }

      f(0,n)
      {
        if(a[i]>k)
          break;
        else
          k+=b[i];
      }
      cout<<k<<endl;
    }

    return 0;

}
