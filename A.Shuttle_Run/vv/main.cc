#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  size_t pos = s.find("xx");
  cout << (pos == string::npos ? n : static_cast<int>(pos) + 1) << endl;
}
