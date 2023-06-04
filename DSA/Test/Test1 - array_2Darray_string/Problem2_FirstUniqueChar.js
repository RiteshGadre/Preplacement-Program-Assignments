// Time Complexity : O(n)
// Space Complexity : O(k)
function firstUniqChar(s) {
    const charFrequency = new Map(); 
  
    for (const char of s) {
      if (charFrequency.has(char)) {
        charFrequency.set(char, charFrequency.get(char) + 1);
      } else {
        charFrequency.set(char, 1);
      }
    }
  
    
    for (let i = 0; i < s.length; i++) {
      if (charFrequency.get(s[i]) === 1) {
        return i; 
      }
    }
  
    return -1; 
  }
  
  const inputString = "leetcode";
  const result = firstUniqChar(inputString);
  console.log(result); // Output: 0 
  
  