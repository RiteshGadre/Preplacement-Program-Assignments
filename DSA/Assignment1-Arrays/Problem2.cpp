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