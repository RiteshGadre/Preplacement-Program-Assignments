// Question 1

// A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:

// - s[i] == 'I' if perm[i] < perm[i + 1], and
// - s[i] == 'D' if perm[i] > perm[i + 1].

// Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return any of them.

// Example 1:

// Input: s = "IDID"
// Output: [0,4,1,3,2]


#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
// Space Complexity : O(n)
vector<int> diStringMatch(string s) {
    int i=0,j=s.length();
    vector <int> v;
    for(int it:s){
        if(it=='I'){
            v.push_back(i);
            i++;
        }
        else{
             v.push_back(j);
            j--;
        } 
    }
    v.push_back(i);
    return v;
}

int main() {
  string s = "IDID";
  vector<int> perm = diStringMatch(s);
  for (int i = 0; i < perm.size(); i++) {
    cout << perm[i] << " ";
  }
  cout << endl;
  return 0;
}
