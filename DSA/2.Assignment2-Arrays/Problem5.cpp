// Question 5
// Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

// Example 1:
// Input: nums = [1,2,3]
// Output: 6


#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force
// - Use 3 loops and try every combination
// - Find the max product and return 
// - Time Complexity : O(n*n*n)
// - Space Complexity : O(1)

int maximumProduct1(vector<int>& nums) {
    int mx= INT_MIN;
    for(int i=0; i<nums.size()-2; i++){
        for(int j=i+1; j<nums.size()-1; j++){
            for(int k=j+1; k<nums.size(); k++){
                mx= max(mx, nums[i]*nums[j]*nums[k]);
            }
        }
    }
    return mx;
}


// Approach 2: Sorting
// - Time Complexity: O(nlogn)
// - Space Complexity : O(1)

int maximumProduct2(vector<int>& nums) {
    int mx= INT_MIN;
    int n= nums.size();
    int case1= nums[0]*nums[1]*nums[n-1];
    int case2= nums[n-1]*nums[n-2]*nums[n-3];
    return max(case1, case2);      
    return mx;
}

int main(){
    vector<int> nums{1, 2, 3};
    int ans;
    ans= maximumProduct1(nums);
    ans= maximumProduct2(nums);
    cout << ans << endl;
}