/*
Problem E: Party Rabbits

SSPC-Belle recieved a pair of baby rabbits, a baby boy rabbit and a baby girl rabbit, as a gift for her sweet-16. The
babies were fully grown after one month. In the next month the rabbits, which are adult now, delivered a new pair of
baby rabbits (a boy and a girl). In the next month these new babies were fully grown and the first pair delivered
another pair of baby rabbits (again a boy and a girl). In the next month the two adult pairs each delivered a pair of
baby rabbits and the babies from the last month were fully grown. Melissa observed that it takes one month for each
pair of baby rabbits to grow up, and after that they deliver a new pair every month. She wants to know her total
number of rabbit pairs in the future (assuming that no rabbit dies). She had 1 pair in month 1, 2 pairs in month 2, 3 pairs
in month 3, 5 pairs in month 4, and so on... The question is how many pairs she would have in month n.

    Input: the first line contains a number m followed by m lines each containing a month number n, and then followed by
    0 in the last line.
    Output: For each number n you should print the total number of rabbits in month n.
    Sample Input: 3 2 4 5 0
    Sample Output: 2 5 8
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//easy DP problem. The answer also happens to be the fibonacci sequence

void solve(int n){ //find the num of rabbits by month n
    vector<int>br(n+1); //br = bunny rabbits
    br[0] = 1; //base cases
    br[1] = 1;
    for(int i = 2; i<=n; ++i){
        br[i] = br[i-1] + br[i-2];
    }
    cout<<br[n]<<"\n";
}

int main(){
    int m, n;
    cin>>m;
    for(int i = 0; i<m; ++i){
        cin>>n;
        solve(n);
    }
    int bananas;  // cin the 0 at the end
    cin>>bananas; // I wonder whos idea this was when they already give m
    return 0;

}