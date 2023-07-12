// https://atcoder.jp/contests/abc097/tasks/abc097_a

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int a, b, c, d; cin >> a >> b >> c >> d;

  if (abs(b - a) <= d && abs(c - b) <= d) cout << "Yes\n";
  else if (abs(c - a) <= d) cout << "Yes\n";
  else cout << "No\n";

  return 0;
}
