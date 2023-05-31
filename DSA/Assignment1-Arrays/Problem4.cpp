#include <bits/stdc++.h>
using namespace std;

// Approach 1: 
// - Iterate the array in reverse order
// - If element is less than 9, add 1 and return the array
// - If element is 9, assign value 0 to element
// - Push 0 to end of the array and assign 1 to 0th index
// - Time Complexity : O(n) 
// - Space Complexity : O(1)

vector<int> plusOne(vector<int>& digits) {
    int n= digits.size();
    for(int i= n-1; i>=0; i--){
        if(digits[i]<9){
            ++digits[i];
            return digits;
        }
        else
            digits[i]= 0;
    }
    digits[0]= 1;
    digits.push_back(0);
    return digits;
}

int main()
{
	/* code */
	vector<int> digits{1, 2, 3, 4};
	plusOne(digits);
	for(auto it: digits) cout << it << " ";
	return 0;
}