#include <iostream>
#include <map>
using namespace std;

int main() {
  int size;
  cin >> size;

  map<int ,int> mp;

  map<int, int>::iterator it = mp.begin();

  // for ( int i = 0; i < size; i++ ) {
  //   int data;
  //   cin >> data;
  //   arr[i] = data;
  // }
  int i = 0;

  while ( i != size ) {
    int data;
    cin >> data;
    mp[data] = data;
    i++;
  }

  cout << mp.size();

}