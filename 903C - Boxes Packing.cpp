/*
One of those problems that seems too complicated to solve at first glance, like i have always said working out a few examples of your own helps in finding patterns.
The solution to the problem is very simple, minimum number of visible boxes is the maximum frequency of size say k out of all different sizes in the given input array.
Now let us understand why
Say there are some numbers 1,2,5,24,30 you can always put the smaller size box into the very next bigger sized box and continue this until at last you have one single box left which is 30 in this case.
But we can never put a box into another box of the same size.
Lets see some examples
1,3,7,7,7,12,12,34 [1->3->7->12->34],[7->12],[7] finally 3 visible(min)
12,20,30,40,40,40,40 [10->20->30->40],[40],[40],[40] 4 visible
10,10,10,20,20,20,30,30,30 [10->20->30],[10->20->30],[10->20->30] 3 visible
10,10,20,20,20,30,30 [10->20->30],[10->20->30],[20] 3 visible
What pattern do we observe? It's always the maximum frequency, out of all frequencies for each size from the input, that determines the answer in the end.
Even logically if you look at it, what happens to boxes of same size? No matter what they remain at last unless you have bigger sized boxes
Now unless the number of bigger sized boxes is greater than this you can never put each of them, even the number of bigger sized boxes is greater that means its frequency is more
Therefore, our answer will be the maximum frequency out of all.
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
    f(0,n)
    cin>>a[i];
    if(n==1)
      cout<<1<<endl;
    else{
      sort(a,a+n);
    ll m=1,temp=1;
    f(1,n){
      if(a[i]!=a[i-1]){
        temp=1;
        continue;
      }
      temp++;
      m=max(m,temp);
    }
    cout<<m<<endl;
  }
    return 0;

}
