#include <iostream>
#include <map>
using namespace std;

int main() {
  int size;
  cin >> size;

  int continuousCount = 0;

  map<int, int> mp;
  
  for ( int i = 0; i < size; i++ ) {
    int data;
    cin >> data;

    mp.insert( pair<int, int>(data, data) );

    if ( mp.find(data - 1) != mp.end() && mp.find(data + 1)  != mp.end() ) {
      continuousCount--;
    } else if ( mp.find(data - 1) == mp.end() && mp.find(data + 1 ) == mp.end()) {
      continuousCount++;
    }
  }

  // for ( map<int, int>:: iterator i = mp.begin() ; i != mp.end(); i++ ) {
  //   cout << i->second;
  // } 

  cout << continuousCount;
  return 0;
}