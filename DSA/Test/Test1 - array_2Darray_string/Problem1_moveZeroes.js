// Approach 2: Using 2 pointers
// - Time Coplexity : O(n)
// - Space Complexity : O(1)
function moveWithApproach2(nums) {
    let i= 0;
    for(num of nums) {
        if(num) nums[i++]= num;
    }

    for(; i<nums.length; i++)
        nums[i]= 0;

    console.log(nums)
}

// Approach 1: Using Extra Space
// - Time Coplexity : O(n)
// - Space Complexity : O(n)
function moveWithApproach1(nums){
    const ans= [];
    let count= 0;

    for(let num of nums) {
        if(num !== 0) 
            ans.push(num);
    }

    let diff= nums.length-ans.length;
    for(let i=0; i<diff; i++)
        ans.push(0)

    console.log(ans);
}




const nums= [0, 1, 0, 3, 12];
moveWithApproach1(nums); // Output: [1, 3, 12, 0, 0]
moveWithApproach2(nums); // Output: [1, 3, 12, 0, 0]
