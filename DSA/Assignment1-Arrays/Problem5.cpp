/*
Q-5 You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

**Example 1:**
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
**Explanation:** The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

*/


#include <bits/stdc++.h>
using namespace std;

// Approach 1: By sorting
// - Insert all the elements of nums2 into the nums1
// - Sort the nums1
// - Time Complexity : O(M*logM)
// - Space Complexity : O(1)

void mergeApproach1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for(int i=m; i<m+n; i++) {
        nums1[i]= nums2[i-m];
    }
    sort(nums1.begin(), nums1.end());
}


// Approach 2: By taking extra space
// - Create new array with M+N elements
// - Create 3 integers i, j and k and initialize with 0
// - Compare both the array elements, and store the minimum of them in new array
// - Iterate array until one of the 2 array reachs limit
// - Again iterate the array, whose limits has not been reached and store the elements
// - Time Complexity : O(M+N)
// - Space Complexity : O(M+N)

void mergeApproach2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> ans(m+n);
    int i= 0;
    int j= 0;
    int k= 0;

    while(i<m && j<n){
        if(nums1[i]<nums2[j]) ans[k++]= nums1[i++];
        else ans[k++]= nums2[j++];
    }
    
    while(i<m) ans[k++]= nums1[i++];
    while(j<n) ans[k++]= nums2[j++];
    
    for(int i=0; i<m+n; i++){
        nums1[i]= ans[i];
    }    
}


// Approach 3: Using 2 pointers
// - Declare 3 variables
// - Initialize i with m-1, j with n-1 and k with m+n-1
// - Iterate both the arrays in decrementing order until one of them reaches 0
// - Now iterate the remaining array, which is fully not tranversed
// - Time Complexity : O(M+N)
// - Space Complexity : O(1)

void mergeApproach3(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i= m-1;
    int j= n-1;
    int k= m+n-1;

    while(i>=0 && j>=0){
        if(nums1[i]>nums2[j])
            nums1[k--]= nums1[i--];
        else
            nums1[k--]= nums2[j--];
    }

    while(i>= 0) nums1[k--]= nums1[i--];
    while(j>= 0) nums1[k--]= nums2[j--];
}


int main(){
	vector<int> nums1{1, 2, 3, 0, 0, 0};
	vector<int> nums2{2, 5, 6};

	int m=3, n=3;

	mergeApproach1(nums1, m, nums2, n);
	mergeApproach2(nums1, m, nums2, n);
	mergeApproach3(nums1, m, nums2, n);


	return 0;
}
