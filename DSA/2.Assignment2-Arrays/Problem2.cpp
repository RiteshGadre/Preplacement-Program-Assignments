// Question 2
// Alice has n candies, where the ith candy is of type candyType[i]. 
// Alice noticed that she started to gain weight, so she visited a doctor. 

// The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). 
// Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice. 

// Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

// Example 1:
// Input: candyType = [1,1,2,2,3,3]
// Output: 3

// Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.




#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using Sorting
// - Sort the array
// - Check how many unique elements are present in array, by checking current element with previous element
// - retun minimum of count and half of size of array
// - Time Complexity : O(nlogn)
// - Space Complexity : O(1)

int distributeCandiesApproach1(vector<int>& candyType) {
    sort(candyType.begin(), candyType.end());
    int count= 1;
    for(int i=1; i<candyType.size(); i++){
        count+= (candyType[i]!= candyType[i-1]);
    }
    int n= candyType.size()/2;
    return min(count, n);
}


// Approach 2: Using Hashmap
// - Iterate the array and store elements into set
// - retun minimum of set length and half of size of arrray
// - Time Complexity : O(logn)
// - Space Complexity : O(logn)

int distributeCandiesApproach2(vector<int>& candyType) {
    unordered_set<int> set;
    for(auto it: candyType){
        set.insert(it);
    }
    return min(set.size(), candyType.size()/2);  
}

int main(){
	vector<int> candyType{1, 1, 2, 2, 3, 3};
	int ans;
	ans= distributeCandiesApproach1(candyType);
	ans= distributeCandiesApproach2(candyType);
	cout << ans << endl;
	return 0;
}