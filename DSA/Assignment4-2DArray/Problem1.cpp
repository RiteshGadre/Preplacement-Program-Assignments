// **Question 1**
// Given three integer arrays arr1, arr2 and arr3 **sorted** in **strictly increasing** order, return a sorted array of **only** the integers that appeared in **all** three arrays.

// **Example 1:**

// Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]

// Output: [1,5]

// **Explanation:** Only 1 and 5 appeared in the three arrays.



#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Using Hashmap and Hashset
// Time Complexity : O(n)
// Space Complexity : O(n)
vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
    // Write your code here
    vector<int> ans;
    map<int, int> map;
    unordered_set<int> set1;
    unordered_set<int> set2;
    unordered_set<int> set3;

    for(auto it: a) set1.insert(it);
    for(auto it: b) set2.insert(it);
    for(auto it: c) set3.insert(it);

    for(auto it: set1) map[it]++;
    for(auto it: set2) map[it]++;
    for(auto it: set3) map[it]++;

    for(auto it: map)
        if(it.second== 3) ans.push_back(it.first);
    return ans;
}

int main(){
    vector<int> a{1,2,3,4,5};
    vector<int> b{1,2,5,7,9};
    vector<int> c{1,3,4,5,8};

    vector<int> ans= findCommonElements(a, b, c);

    for(auto it: ans) cout << it << " ";

    return 0;
}