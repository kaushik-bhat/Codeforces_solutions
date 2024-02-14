/*
The problem seems overly complicated until you make some cases only to find out that it is very simple.
Some facts :
  2 is the only even prime number all other prime numbers are odd
  Product of any number of odd numbers is odd, product of even and odd number is even
  Subtraction of an odd number from an odd number results in an even number[Ex: 11-3=8 , 27-5=22]
  Subtraction of an even number from an even number results in an even number[Ex: 12-4=8 , 100-10=90]
Let us make some cases and solve the problem
Case 1 :
  The given number is a prime number [Note->Considering 2 as prime or not prime both gives same solution, because if prime we print 1, n/2 or 2/2 also is equal to 1]
  We print 1 directly because the smallest prime divisor of a prime number is itself, so we can get to 0 in 1 step.
Case 2 :
  The given number is even.
  We print n divided by 2 as our answer n/2.
  Because the smallest prime divisor of an even number is 2 always, and when you subtract 2 from any even number the resulting number is also even.
  Now this process of subtracting 2 continues till we reach 0, and the total steps would be n/2 .
  Ex: 10 --> 8 --> 6 --> 4 --> 2 --> 0 , total 5 steps
Case 3 :
  The given number is odd.
  We print n divided by 2 plus 1 as our answer n/2 + 1.
  Because the smallest prime divisor of an odd number will always be odd and when you subtract an odd number from an odd number the result number is even.
  We reduced the problem to Case 2 in 1 step, now the solution is n/2 because we have proved that already in Case 2.
  Ex: 15(3 is the smallest prime divisor)--> 12 --> 10 --> 8 --> 6 --> 4 --> 2 --> 0 , total 5 + 1 = 6 steps.
*/
#include <bits/stdc++.h>
using namespace std;

#define f(a,b) for(ll i=a;i<b;i++)
#define ll long long int
#define pb(n) push_back(n)
#define endl "\n"

const ll mod = 10e9+7;

bool isprime(ll n){
  if(n%2==0)
    return false;
  for(ll i=3;i<=sqrt(n);i+=2){
    if(n%i==0){
      return false;
    } 
  }
  return true;
}

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
    if(isprime(n))
      cout<<1<<endl;
    else if(n%2==0)
      cout<<n/2<<endl;
    else{
      for(ll i=3;i<=sqrt(n);i+=2){
      if(isprime(i) && n%i==0){
        n-=i;
        break;}
    }
    cout<<(n/2)+1<<endl;
}
return 0;
}
