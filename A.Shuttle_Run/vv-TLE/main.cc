#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  string s;
  cin >> s;
  for (int i = 0; i < n - 1; i++) { // worst O(N)
    if (s[0] == 'x' && s[1] == 'x') {
      cout << i + 1 << endl;
      return 0;
    }
    for (int j = 0; j < n - 1; j++) s[j] = s[j + 1]; // O(N)
  }
  cout << n << endl;
}
