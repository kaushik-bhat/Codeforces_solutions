/*
The solution below is certainly not the shortest solution to this problem.
Let us first understand what we have to solve, given an array of n integers we have to output the maximum possible value of k
Where we can chose any index i and subtract the element a(i) with k any number of times, with the goal to make all the elements of the array equal
Firstly it is very clear that it is optimal to make all the elements equal to the smallest element in the array.
Also we need not worry about duplicates if at all they exist in the array, that is why i have used set container in my code.
Let us make cases and solve the simple subproblems
Case 1 : 1 distinct number in array
         we can assign any value to k and we meet our goal, so we print -1
Case 2 : 2 distinct numbers in the array
         the difference between the larger number and smaller number is the maximum value that k can take
         Ex: 13, 29 --> 29-13=16, no value greater than 16 solves the problem optimally
Case 3 : 3 distinct numbers in the array
         When there are 3 or more distinct numbers in the array, we calculate the difference between each element with the smallest element
         Then calculate the gcd for these differences which is k, this is the solution because since k is the greatest common devisor of all the differences
         There is no other maximum value and we for sure know that if we subtract the elements of array with k some x no of times we can make it equal to the smallest element.
*/
  #include <bits/stdc++.h>
using namespace std;

#define f(a,b) for(ll i=a;i<b;i++)
#define ll long long int
#define pb(n) push_back(n)
#define endl "\n"

const ll mod = 1e9+7;

ll gcd(ll a, ll b)
{
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

ll findGCD(vector<ll> arr)
{
  ll result = arr[0];
  for (int i = 1; i < arr.size(); i++)
  {
    result = gcd(arr[i], result);
  
    if(result == 1)
    {
    return 1;
    }
  }
  return result;
}

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
      ll n;
      cin>>n;
      ll temp,min,diff;
      vector<ll> arr;
      set<ll> x;
      f(0,n)
      {
        cin>>temp;
        x.insert(temp);
      }
      if(x.size()==1)
      {
        cout<<"-1"<<endl;
        continue;
      }
      if(x.size()==2)
      {
        set<ll>::iterator one,two;
        one=x.begin();
        two=x.begin();
        two++;
        cout<<*two-*one<<endl;
        continue;
      }
      if(x.size()>=3)
      {
        set<ll>::iterator one,two;
        one=x.begin();
        two=x.begin();
        two++;
        min=*two-*one;
        arr.pb(min);
        two++;
        for(;two!=x.end();two++)
        {
          temp=*two-*one;
          arr.pb(temp);
        }
          cout<<findGCD(arr)<<endl;
      }
    }

    return 0;

}
