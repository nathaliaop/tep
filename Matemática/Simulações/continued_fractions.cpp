// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=775

/*
The middle of adventure, such a perfect place to start
⣿⣿⣿⣿⣿⣿⣿⢿⠟⢿⣿⣿⣿⣿⠿⠛⠛⠿⢿⣿⣿⣿⣿⠛⣿⢿⣿⣿⣿⣿
⣿⣿⣿⡿⢿⣿⣿⣄⠄⣼⣿⡿⠋⠄⠄⠄⠄⠄⠄⠄⠛⣿⣿⠄⢀⣤⣿⣿⣿⣿
⣿⣿⣷⣤⣸⣿⠛⡛⢛⣿⠋⠄⠄⢀⠄⠄⠄⠄⠄⠄⠄⠘⣿⣿⡿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⡿⠁⠄⠁⠈⠄⠄⠄⠄⣿⡀⠄⠄⠄⠄⠄⠄⠄⠓⠸⠏⠄⢹⣿⣿⣿
⣿⣿⣿⡿⠄⠄⠄⠄⠄⠄⠄⢠⠿⠿⢻⣦⣤⣠⠄⠄⠄⠄⠄⠄⠄⠄⠈⠻⣿⣿
⣿⣿⡿⠁⠄⠄⠄⠄⠈⠄⠄⢸⣿⣿⣿⣿⣿⢭⡛⡀⠄⠄⠨⠄⠄⠄⠄⠄⣿⣿
⣿⣿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠻⣧⡀⣈⣿⣿⠟⠄⠄⠠⢇⠄⠄⠄⠄⠄⣿⣿
⣿⡁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⢀⣉⡉⠉⠄⠄⠄⠄⠄⠰⠂⠄⠄⠄⠄⢹⣿
⣿⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣿⠿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠘⣿
⣿⣿⣶⣤⣤⣄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣼⣿
*/
#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ff first
#define ss second
#define ll long long
#define int long long
#define ld long double

using namespace std;

vector<ld> root(ld a, ld b, ld c) {
  vector<ld> ans;
  if (a == 0) {
    ans.pb(-c / b);
    return ans;
  }
  ld delta = b * b - 4 * a * c;
  if (delta > 0) {
    ans.pb((-b + (ld)sqrt(delta)) / (2 * a));
    ans.pb((-b - (ld)sqrt(delta)) / (2 * a));
  }
  if (delta == 0) {
    ans.pb(-b / (2 * a));
  }
  sort(ans.begin(), ans.end());
  return ans;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  ld a, b, c; cin >> a >> b >> c;
  if (a == 0 && b == 0 && c == 0) {
    cout << "-1\n";
    return 0;
  } else if (a == 0 && b == 0 && c != 0) {
    cout << "0\n";
    return 0;
  }
  vector<ld> ans = root(a, b, c);
  cout << ans.size() << '\n';
  for (auto u : ans) {
    cout << fixed << setprecision(12) << u << '\n';
  }

  return 0;
}
