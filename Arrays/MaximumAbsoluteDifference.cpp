#include<iostream>
#include<vector>

using namespace std;

int maxArr(vector<int> &A){
  vector<int> plus,minus;
  int maxplus =-1000000;   //holds maximum value of A[i] + i 
  int minplus = 1000000;   //holds minimum value of A[i] + i
  int maxminus = maxplus;  //holds maximum value of A[i] - i
  int minminus = minplus;  //holds minimum value of A[i] - i
  for(int i=0; i<A.size(); i++) {
    if((A[i] + i) > maxplus) {
      maxplus = A[i] + i;
    }
    if((A[i] + i) < minplus) {
      minplus = A[i] + i;
    }
    if((A[i] - i) > maxminus) {
      maxminus = A[i] - i;
    }
    if((A[i] - i) < minminus) {
      minminus = A[i] - i;
    }
  }
  int plusRes = maxplus - minplus;
  int minusRes = maxminus - minminus;
  if(plusRes > minusRes) {
    return plusRes;
  }
  else {
    return minusRes;
  }
}
