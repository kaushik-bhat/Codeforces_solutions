/*
The problem tells that you should choose a minimum non-negative integer D and for each A(i) you can add D / subtract D / leave A(i) unchanged
But the important point to understand is that you cannot perform this operation any number of times, you can do the addition or subtraction of D only once for a given A(i)
Isn't it common sense? Otherwise, we could always choose 1 perform operations any number of times and make the elements equal:)
Print a minimum non-negative integer D if at all such a value exists else print -1
Refer to this GFG page to understand "sets" in C++ --> https://www.geeksforgeeks.org/set-in-cpp-stl/
Whatever values you insert into a set, it stores only the unique values that is duplicates are not stored and also by default they are stored in ascending order.
Let us understand the problem by making a few cases:
Case 1:
  All the elements of the array are equal
  We can print 0 since all the elements are already equal therefore our objective is completed.
Case 2:
  There are 2 unique elements in the array [Note: array need not contain 2 elements, Ex: [1,2,1,1,1,1], [1,1,2,1,2,1] , [1,2] , [2,2,2,2,1] all are arrays with 2 unique elements 1 and 2
  We shouldn't jump into printing difference between them as the answer
  Because lets say the numbers are 5 and 11, diff=6 but minimum non-negative integer D is 3, 5+3=8 and 11-3=8 thus the array is equal
  Case 2.1 :
    If the difference between the two elements is even, D = difference/2 because they can always meet halfway through.
  Case 2.2 :
    If the difference between the two elements is odd, D = difference because now there is no scope for them to meet at an exact number midway.
Case 3 :
  Three unique elements in the array is an interesting case
  Since in a set we know the elements are sorted in ascending order by default, let difference = 2nd element - 1st element
  Now if and only if, 3rd element - 2nd element = difference(calculated earlier) D = difference else D will be -1 because no valid value exists.
  Let us understand why, If the differences are different you can never make them equal by taking the same D value, you never get a common meeting point
  Say 4,6,9 --> if you choose D=2 4+2=6 but 9-2=7, and D=3 9-3=6 but 4+3=7
Case 4:
  There are more than 3 unique elements( >= 3 ) , we can directly print -1
  Because by chosing a single D value you can never add/subtract it from 4 distinct numbers either 0/1 time to make them equal.
  Say 4,5,6,7 or 7,12,65,467 It is difficult to even assume what their common meeting point can be
  After deciding that you will realise that each number has different D requirements to reach there in a single step.
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
    
    ll n,temp;
    cin>>n;
    set<ll> a;
    f(0,n){
      cin>>temp;
      a.insert(temp);
    }
    if(a.size()==1)
      cout<<0<<endl;
    else if(a.size()==2){
      set<ll>::iterator x,y;
      x=a.begin();
      y=a.begin();
      y++;
      if((*y-*x)%2==0)
        cout<<((*y-*x)>>1)<<endl;
      else
        cout<<(*y-*x)<<endl;
    }
    else if(a.size()==3){
      set<ll>::iterator x,y;
      ll d;
      x=a.begin();
      y=a.begin();
      y++;
      d=*y-*x;
      x++;
      y++;
      if((*y-*x)==d)
        cout<<d<<endl;
      else
        cout<<-1<<endl;
    }
    else{
      cout<<-1<<endl;
    }

    return 0;

}
