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
  for (int i = 0; i < n - 1; i++) { // O(N)
    if (s[0] == 'x' && s[1] == 'x') {
      cout << i + 1 << endl;
      return 0;
    }
    for (int j = 1; j < s.size(); j++) s[j - 1] = s[j]; // O(N)
  }
  cout << n << endl;
}
