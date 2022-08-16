/*
Palindrome Index
Basically, determine if you can make a palindrome by removing one 
index of the string. If yes, print that index of removal. If not
possible return -1. If the input is already a palindrome return -1. 

Input: int t (test cases)
        the following t lines will be string s
Output: described above

Sample input: 3 aaab baa aaa
sample output: 3 0 -1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline bool check_palindrome(string s){
    string s_reversed = s;
    reverse(s_reversed.begin(), s_reversed.end());
    if(s == s_reversed){
        return true;
    }
    return false;
}

void solve(){
    string s;
    cin>>s;
    //check if already a palindrome
    bool check = check_palindrome(s);
    if(check){
        cout<<"-1\n";
        return;
    }

    //remove each index and check if palindrome
    for(int i = 0; i<s.size(); ++i){
        string temp = s;
        temp.erase(temp.begin()+i);
        bool check = check_palindrome(temp);
        if(check){
            cout<<i<<"\n";
            return;
        }
    }
    
    cout<<"-1\n";
}


int main(){
    int t;
    cin>>t;
    for(int i = 0; i<t; ++i){
        solve();
    }
}