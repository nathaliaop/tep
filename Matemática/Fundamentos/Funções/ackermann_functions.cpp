// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=307

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
#define ff first
#define ss second
#define ll long long
#define int long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ld long double

using namespace std;

map<ll, ll> dp;

ll ackermann(int i) {
  if (i == 1) return dp[1] = 0;

  if (dp.find(i) != dp.end()) return dp[i];

  if (i % 2 == 1) dp[i] = ackermann(3 * i + 1) + 1;
  else dp[i] = ackermann(i / 2) + 1;

  return dp[i];
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int l, r;
  while (cin >> l >> r) {
    if (l == 0 && r == 0) break;
    pll mx = mp(-1, -1);

    if (l > r) swap(l, r);

    for (int i = l; i <= r; i++) {
      ll len = 3;
      if (i != 1) len = ackermann(i);
      if (len > mx.ff) {
          mx.ff = len;
          mx.ss = i;
        }
      }

      printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", l, r, mx.ss, mx.ff);
    }

    return 0;
  }
