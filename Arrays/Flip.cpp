#include<iostream>
#include<vector>
#include<string>

using namespace std;

/* Problem Statement 

You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, 
you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.

Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform the operation, return an empty array.
 Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

Notes:

Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.
For example,

S = 010

Pair of [L, R] | Final string
_______________|_____________
[1 1]          | 110
[1 2]          | 100
[1 3]          | 101
[2 2]          | 000
[2 3]          | 001

We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].
Another example,

If S = 111

No operation can give us more than three 1s in final string. So, we return empty array [].

*/

/*  
SOLUTION APPROACH
  The same approach used for Maximum sum contiguous sub array.
  Maintain two pointers indicating the array which is being considered at present. (left and right) 
  Maintain with them an 'INCREASE' value that holds how much ones would be increased if we flip the presently evaluated sub array.
  As long as the increase value is non negative, keep extending the presently considered array.
  Maintain two pointers indicating the array which led to the maximum increase till now. (maxleft and maxright)
  These pointers get updated whenever the presently considered array has an increase greater than max increase.
*/

vector<int> flip(string A) {
  int left = -1;
  int right = -1;
  int increase = 0;
  int length = A.length();
  int maxleft = -1;
  int maxright = -1;
  int maxincrease = 0;
  for(int i = 0; i < length; i++) {
    if(A[i] == '0') {
      if(left == -1) {
        left = i;
      }
      increase++;
      right = i;
      if(increase > maxincrease) {
        maxleft = left;
        maxright = right;
        maxincrease = increase;
      }
    }
    else {
      if((increase - 1) < 0) {
        left = -1;
        right = -1;
        increase = 0;
      }
      else {
        increase--;
        right = i;
      }
    }
  }
  vector<int> res;
  if(maxleft == -1) {
    return res; 
  }
  res.push_back(maxleft+1);
  res.push_back(maxright+1);
  return res;
}
