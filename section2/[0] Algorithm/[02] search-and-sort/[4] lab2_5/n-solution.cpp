#include <iostream>

using namespace std;

int main() {
  int n = 0;

  cin >> n;

  int *hours = new int[25];

  for (int i = 0; i < n; i++) {
    int exit = 0;
    int enter = 0;

    cin >> enter >> exit;

    for (int j = enter; j <= exit; j++) {
      hours[j]++;
    }
  }

  int max = 0;
  int end = 0;
  int start = 0;
  int streak = true;

  for (int i = 1; i < 25; i++) {
    if (hours[i] > max) {
      start = i;
      streak = true;
      max = hours[i];
    }

    if (hours[i] != max) {
      streak = false;
    }

    if (hours[i] == max && streak) {
      end = i;
    }
  }

  cout << start << " " << end << " " << max << endl;

  return 0;
}