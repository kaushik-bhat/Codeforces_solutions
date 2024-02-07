/*
We know that
odd + odd (or) even + even = even
even + odd (or) odd + even = odd
Sum of odd numbers, is odd if the count is odd and even if the count is even whereas sum of even numbers is even irrespective of their count.
We just want the count of odd numbers in the given array, also in my code i have used a set but this can be solved using even an array.
Firstly find the sum of all elements in the array and parallelly count the number of odd numbers in the array.
Case 1 :
  Sum is odd
  Print YES because our objective has already been achieved.
Case 2 :
  Sum is even
  Case 2.1 :
    If all the elements in the array are odd or if there are no odd elements then we can never achieve our odd sum objective
    Because if sum is even and odd_count = n, that means there are even number of odd elements in the array, irrespective of number of times we assign any element with the other
    it will remain odd and the total sum can never be even.
  Case 2.2 :
    Also if sum is even and odd_count = 0, that means there are no odd numbers in the array and it contains only even numbers, we can choose any element and assign it with 
    other element and it will still remain even because we have got no odd number in the array and the total sum remains even
  For BOTH of these cases we can print NO
For any other case other than these three we can print YES
Let us understand why, in all the other cases the array is a combination of some number of even numbers and remaining odd numbers
We can pick any odd or even number and assign it to any even or odd number respectively thus changing parity of the total sum.
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
    while(t--)
    {
      ll n,x,odd_count=0,sum=0;
      cin>>n;
      set<ll> s;
      f(0,n)
      {
        cin>>x;
        sum+=x;
        if(x&1)
          odd_count++;
        s.insert(x);
      }
      if(sum&1)
        cout<<"YES"<<endl;
      else
      {
        if(s.size()==1)
          {
            cout<<"NO"<<endl;
              continue; 
            }
          if(odd_count == n || odd_count == 0)
          {
            cout<<"NO"<<endl;
            continue;
          }
          cout<<"YES"<<endl;
      }
    }

    return 0;

}
