/*
The problem is very easy, but shall we agree that it's a little tricky?
Firstly let us count the number of odd and even numbers in the array.
Now let us make cases or break the problem into small problems.
We know that always
odd + odd (or) even + even = even
odd + even (or) even + odd = odd
Case 1 :
  There are no odd numbers in the array then clearly it is not possible to get an odd sum no matter what the value of x is.
Case 2 :
  All the numbers in the array are odd numbers.
  We will have to look at two subcases now.
  Case 2.1 :
    if the given x is odd then YES we can select any of the x numbers from the array as sum of odd no of odd numbers will always be odd.
  Case 2.2 :
    if the given x is even then NO cause sum of even no of odd numbers will result in an even sum.
Case 3 :
  Again now we can have two cases 
  Case 3.1 :
    There are odd no of odd numbers in the array
    We can always choose all odd numbers and remaining even numbers till we have x no of elements and the sum will be odd.
    odd no of odd numbers have sum odd and adding even numbers to it doesn't change the output.
  Case 3.2 :
    When there are even no of odd numbers in the array.
    It is similar to previous case we just leave one odd number include all other even numbers see if this count of total numbers is >= x (no of elements required).

I hope this explanation was helpful.
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
    
    ll t;
    cin>>t;
    while(t--){
      ll n,x,temp,odd=0,even=0;
      cin>>n>>x;
      f(0,n){
        cin>>temp;
        if(temp&1)
          odd++;
        else
          even++;
      }
      if(odd==0){
        cout<<"No"<<endl;
        continue;
      }
      if(odd==n && (x%2==0)){
        cout<<"No"<<endl;
        continue;
      }
      if(odd&1){
        cout<<"YES"<<endl;
      }
      else{
        if(((odd-1)+even)>=x)
          cout<<"Yes"<<endl;
        else
          cout<<"No"<<endl;
      }
    }

    return 0;

}
