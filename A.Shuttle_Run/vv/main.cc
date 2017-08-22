#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  size_t pos = s.find("xx");
  cout << (pos == string::npos ? -1 : static_cast<int>(pos)) << endl;
}
