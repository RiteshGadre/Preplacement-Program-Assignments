// - Time Coplexity : O(log x)
// - Space Complexity : O(1)

function mySqrt(x) {
  if (x === 0 || x === 1) {
    return x;
  }

  let left = 0;
  let right = Math.floor(x / 2) + 1;

  while (left < right) {
    const mid = Math.floor((left + right) / 2);
    const square = mid * mid;

    if (square === x) {
      return mid;
    } else if (square < x) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return left - 1;
}

const input1 = 4;
const result1 = mySqrt(input1);
console.log(result1);

const input2 = 8;
const result2 = mySqrt(input2);
console.log(result2);
