#include<iostream>
#include<vector>

using namespace std;

/* Problem Statement 

You are given a 1D integer array B containing A integers.

Count the number of ways to split all the elements of the array into 3 contiguous parts so that the sum of elements in each part is the same.

Such that : sum(B[1],..B[i]) = sum(B[i+1],...B[j]) = sum(B[j+1],...B[n])



Problem Constraints
1 <= A <= 105

-109 <= B[i] <= 109



Input Format
First argument is an integer A.

Second argument is an 1D integer array B of size A.



Output Format
Return a single integer denoting the number of ways to split the array B into three parts with the same sum.

*/

int solve(int A, vector<int> &B) {
  long long int total = 0;
  int permutes = 0;
  for(int i = 0; i < A; i++) {
    total += B[i];  
  }
  if(total % 3 != 0) {
    return 0;             //can be partitioned into three parts only if total divisible by 3
  }
  long long int firstbreak = total/3;
  long long int secondbreak = firstbreak*2;
  int firstReached = 0;
  int secondReached = 0;
  long long int cumulative = 0;
  for(int i = 0; i < A; i++) {
    cumulative += B[i];
    if(cumulative == firstbreak) {
      firstReached++;
    } 
    if(cumulative == secondbreak && firstReached != 0) {
      secondReached++;
      permutes += firstReached;
    }
  }
  if(total == 0) {   //special case when all breakpoints are at total zero.
    int actual = firstReached - 1;
    if(actual < 2) {
      return 0;
    }
    else {
      int res = (actual*(actual-1))/2;
      return res;
    }
  }
  return permutes;
}
