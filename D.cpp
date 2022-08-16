/*
Problem D: Caesar's Cipher

SSPC-Belle wanted to make sure no one at the party can steal her confidential messages between her friends. She
recalls how Julius Caesar protected his confidential information by encrypting it using a cipher. Caesar's cipher shifts
each letter by a number of letters. If the shift takes you past the end of the alphabet, just rotate back to the front of
the alphabet. In the case of a rotation by 3, w, x, y, and z, would map to z, a, b, c.
Original alphabet:   abcdefghijklmnopqrstuvwxyz
Alphabet rotated +3: defghijklmnopqrstuvwxyzabc
Note: The cipher only encrypts letters; symbols, such as -, remain unencrypted.

Input format: The first line contains the integer, n the length of the unencrypted string. The second line contains the unencrypted
string, s. The third line contains k, the number of letters to rotate the alphabet by.
Constraints: 1 <= n <= 100
             0 <= k <= 100
             s is a valid ASCII string without any spaces.
Output format: For each test case, print the encoded string.

Sample input: 11 middle-Outz 2 
Sample output: okffng-Qwvb
*/

#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

string solve(){
    int n, k;
    string s;
    cin>>n>>s>>k;

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string upperbet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    vector<char>shifted (n);

    for(char c: s){
        //is alpha?
        if(isalpha(c)){
            //lower case?
            if(islower(c)){
                for(int i = 0; i<26; ++i){
                    if(c == alphabet[i]){
                        //loop
                        if(i+k>=26) shifted.push_back(alphabet[i+k-26]);
                        //norm
                        else shifted.push_back(alphabet[i+k]);
                    }
                }
            }else{ //upper case
                for(int i = 0; i<26; ++i){
                    if(c == upperbet[i]){
                        //loop
                        if(i+k>=26) shifted.push_back(upperbet[i+k-26]);
                        //norm
                        else shifted.push_back(upperbet[i+k]);
                    }
                }
            }
        }else{
            shifted.push_back(c);
        }
    }
    
    string encoded(shifted.begin(), shifted.end());
    return encoded;
}

int main(){
    string encoded = solve();
    cout<<encoded<<"\n";
}