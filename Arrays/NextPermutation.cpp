#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

/* Problem statement
  
  Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers for a given array A of size N.
  If such arrangement is not possible, it must be rearranged as the lowest possible order i.e., sorted in an ascending order.

Note:
  1. The replacement must be in-place, do **not** allocate extra memory.
  2. DO NOT USE LIBRARY FUNCTION FOR NEXT PERMUTATION. Use of Library functions will disqualify your submission retroactively and will give you penalty points.

Input Format:
  The first and the only argument of input has an array of integers, A.
  
Output Format:
  Return an array of integers, representing the next permutation of the given array.

Constraints:
  1 <= N <= 5e5
  1 <= A[i] <= 1e9


*/

/* SOLUTION APPROACH

    -> Start from the reverse of the vector.
    -> Find the first pair where there is a fall in magnitude while moving from i to i-1.
    -> from index i till end, find the smallest element larger than A[i-1].
    -> Swap the positions of the second largest element found above with A[i-1].
    -> Arrange in ascending order all elements from index i till the end.
*/

vector<int> nextPermutation(vector<int> &A) {
  int isGreatest = 1;
  int swapPos = -1;
  int replacer = 0;
  for(int i = A.size() - 1; i >= 1; i--) {
    if(A[i] > A[i-1]) {
      isGreatest = 0;
      swapPos = i - 1;
      replacer = A[i-1];
      break;
    }
  }
  vector<int> result;
  if(isGreatest == 1) {
    for(int i = A.size() - 1; i >= 0; i--) {
      result.push_back(A[i]);
    }
    return result;
  }
  int max = 1000000001;
  int secondPos = 0;
  for(int i = swapPos; i < A.size(); i++) {
    if(A[i] > replacer && A[i] < max) {
      max = A[i];
      secondPos = i;
    }
  }
  int temp = A[swapPos];
  A[swapPos] = A[secondPos];
  A[secondPos] = temp;
  sort(A.begin() + swapPos + 1, A.end());
  for(int i = 0; i < A.size(); i++) {
    result.push_back(A[i]);
  }
  return result;
}
