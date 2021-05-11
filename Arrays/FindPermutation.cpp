#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

/* Problem statement

  Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.
  D means the next number is smaller, while I means the next number is greater.

  Notes
    Length of given string s will always equal to n - 1
    Your solution should run in linear time and space.
  Example :

  Input 1:
    n = 3
    s = ID
    Return: [1, 3, 2]

*/

/* 
  SOLUTION APPROACH

    Start building the array from the end instead from the beginning. This helps us to concentrate on only one side of the condition in String without worrying about 
    if we will be left with numbers or not. This effectively reduces our question to a string of size one less.

    if Last element of String is I, insert maximum possible, else insert minimum possible and update the max min values.
*/
vector<int> findPerm(const string A, int B) {
  vector<int> res;
  int max = B;
  int min = 1;
  for(int i = A.length()-1; i>=0; i--) {
    if(A[i] == 'I') {
      res.push_back(max);
      max--;
    }
    else {
      res.push_back(min);
      min++;
    }
  }
  res.push_back(max);
  vector<int> finres;
  for(int i = res.size()-1; i>=0; i--) {
    finres.push_back(res[i]);
  }
  return finres;
}

