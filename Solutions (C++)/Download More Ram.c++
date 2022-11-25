/* 

                                                              A. Download More RAM
                                                           time limit per test1 second
                                                        memory limit per test256 megabytes
                                                              inputstandard input
                                                             outputstandard output
                                                             

Problem A1629: https://codeforces.com/contest/1629/problem/A
My solution: https://codeforces.com/contest/1629/submission/149778102

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr); // faster input and output, cout and cin
    int testCases,startingRam,arrayLength;
    cin >> testCases;
    while (testCases--) {
        cin >> arrayLength >> startingRam;
        pair<int,int> ramDeals[arrayLength]; // we can also use two different arrays to store matching pairs
        
        for (int index = 0;index < arrayLength;index++)   {
            cin >> ramDeals[index].first;
        }
            
        for (int index = 0;index < arrayLength;index++) {
            cin >> ramDeals[index].second;
        }
        
        sort(ramDeals,ramDeals+arrayLength); // faster than quicksort()
        
        // after sorting, if we can buy the ram than it is always profitable that we buy it
        // if we can't buy [currentIndex].first then we cannot buy [currentIndex+1].first, [currentIndex+2].first and so on
        
        for (int index = 0;index < arrayLength;index++) {
            if (startingRam >= ramDeals[index].first) {     
                startingRam += ramDeals[index].second;
            }
            else {
                break;
            }
        }
        
        cout << startingRam << endl;
   }
   return 0; // terminates faster
}
