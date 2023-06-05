/*Q2. Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
- Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
- Return k.
**Example :**
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_*,_*]

**Explanation:** Your function should return k = 2, with the first two elements of nums being 2. It does not matter what you leave beyond the returned k (hence they are underscores)[
*/



#include <bits/stdc++.h>
using namespace std;

// Approach: Using an extra space
// - Declare new array - temp
// - Iterate the the main array and add all the elements in temp array which is not equal to val
// - Iterate the temp array and add all elements into the main array
// - Now, return the size of the temp array
// - Time Complexity : O(N)
// - Space Complexity : O(N)

int removeElementApproach1(vector<int> &nums, int val){
	vector<int> ans;
    int count= 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]!= val)
        	ans.push_back(nums[i]);
    }
    
    for(int i=0; i<ans.size(); i++) {
    	nums[i]= ans[i];
    }
    return ans.size();
}


// Approach2: Without using an extra space
// - Declare and int j and initialize it with 0
// - Iterate through the main array
// - If curreent element is not equal to val add it with index of j
// - Return the j
// - Time Complexity : O(N)
// - Space Complexity : O(1)

int removeElementApproach2(vector<int> &nums, int val){
	int j= 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]!= val)
            nums[j++]= nums[i];
    }
    return j;
}

int main(){
	vector<int> nums;
	nums= {3,2,2,3};
	int n;
	n= removeElementApproach1(nums, 3);
	// n= removeElementApproach2(nums, 3);

	for(int i=0; i<n; i++){
		cout << nums[i] << " " ;
	}
	cout << endl;
	return 0;
}
