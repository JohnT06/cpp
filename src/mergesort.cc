#include <iostream>
#include <vector>

using namespace std;

vector<int> merge_sort(vector<int> lhs, vector<int> rhs) {
  // Homework: update code here.
  vector<int> out;
  int i=0, j=0;
  while(i<lhs.size() && j<rhs.size()) {
      if(lhs[i] > rhs[j]) {
          out.push_back(rhs[j++]);
      } else {
          out.push_back(lhs[i++]);
      }
  }
  while(i<lhs.size()) {
      out.push_back(lhs[i++]);
  }
  while(j<rhs.size()) {
          out.push_back(rhs[j++]);
  }
  return out;
}

int main() {
  //vector<int> merged = merge_sort({1, 2, 3}, {1, 3, 4});
  //vector<int> merged = merge_sort({1, 2, 3}, {4, 5, 6});
  //vector<int> merged = merge_sort({1, 2, 3}, {});
  //vector<int> merged = merge_sort({},{1, 2, 3});
  vector<int> merged = merge_sort({},{});
  for (vector<int>::iterator i = merged.begin(); i != merged.end(); ++i) {
    cout << *i << ' ';
  }
  cout << endl;
}
