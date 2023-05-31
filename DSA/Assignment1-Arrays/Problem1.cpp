#include<bits/stdc++.h>
using namespace std;

// Approach 1: Using brute force
// - Define outer loop, initialize it with 0 and iterate upto secondlast elements of an array
// - Define inner loop, initialize it with next element of outer loop and iterate upto last element of an array
// - Return i and j, if sum of 2 elements is target
// - Time Complexity : O(N*N)
// - Space Complexity : O(1)

vector<int> usingBruteForce(vector<int> &nums, int target){
	for(int i= 0; i<nums.size()-1; i++){
		for(int j= i+1; j<nums.size(); j++){
            if(nums[i]+nums[j]== target)
                return {i, j};
        }
    }
    return {-1, -1};
}


// Approach 2: Using Hashmap
// - Define hashmap of <int, int>, where we will going to store element and its index
// - Define loop, initialize it from 0th element and iterate upto last element of an array
// - Find (target - currElement) in map
// 		- If element is not present, insert element into the map
// 		- If element is present return (target-currElement)element along with current array element
// - Time Complexity : O(N)
// - Space Complexity : O(N)

vector<int> usingHashMap(vector<int> &nums, int target){
	unordered_map<int, int> map;

    for(int i=0; i<nums.size(); i++){
        if(map.find(target-nums[i]) == map.end())
            map[nums[i]] = i;
        else
            return {map[target-nums[i]], i};
    }
    return {-1, -1};
}


int main(){
	vector<int> arr{2,7,11,15};
	int target= 9;
	vector<int> ans;
	ans= usingBruteForce(arr, target);
	ans= usingHashMap(arr, target);
	for(int i=0; i<ans.size(); i++){
		cout << ans[i] << " ";
	}
	return 0;
}