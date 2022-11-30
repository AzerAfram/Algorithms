/*
                                                         B. DIV + MOD
                                                  time limit per test2 seconds
                                               memory limit per test256 megabytes
                                                      inputstandard input
                                                     outputstandard output
                                                     
Problem A1629: https://codeforces.com/contest/1650/problem/B
My solution: https://codeforces.com/contest/1650/submission/149867297

*/

#include <iostream>
typedef long long ll;
using namespace std;


// The problem has two parts 1. x/a, 2. x % a
// The answer to each test case is the combined maximum of both parts
// It is obvious that it is best to maximize x in order to maximize part 1
//   Knowing the above, we can initially set x to r (the maximum)
// Sometimes, though, it is more profitable for us to decrease x in order to maximize part 2

/*   
     Example: l = 2, r = 24, a = 6
     at first, x = 24
     ans = 24/6 = 4   +   24 % 6 = 0   =   4
     
     but since, in this case, it is more profitable for us to decrease x by 1:
     x = 23
     ans = 23/6 = 3   +   23 % 6 = 5   =   8
     
     Even if r = 27, for example, we could decrease x (x = r) in order to maximize part 2 
     In other words, if x % a != 0 then we can decrease x by x % a which would cause x/a to be an integer and x % a = 0
     Then we could nudge x down by just 1 more to get the maximum value of part 2 at the cost of a decrease of 1 from x/a
     To find the answer we can check if it is more profitable to maximize part 2 after maximizing part 1
     
*/
int main() {
   ios::sync_with_stdio(false);cin.tie(nullptr);
   int testCase;
   cin >> testCase;
   while(testCase--) {
     long long l,r,a;
     cin >> l >> r >> a;
     ll ans = 0;
     ll temp = r - (r%a) -1;
     if(temp >= l) {
         ll temp1 = temp/a + temp%a;
         ll temp2 = r/a + r%a ;
         ans = max(temp1,temp2);
   }
   
     else ans = r/a + r%a ;
     cout << ans << '\n';
     
  }
  return 0;
}
