// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=557

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

using namespace std;

const int MAX = 1e3+10;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  while (cin >> n) {
    if (n == -1) break;
    int ori = n;

    bool found = false;
    for (int i = MAX; i >= 1; i--) {
      n = ori;
      bool stop = false;
      for (int j = 0; j < i; j++) {
        if (n % i != 1) {
          stop = true;
          break;
        }
        n--;
        n -= (n / i);
      }

      if (stop) continue;

      if (n % i == 0) {
        found = true;
        printf("%lld coconuts, %lld people and 1 monkey\n", ori, i);
        break;
      }
    }

    if (!found) printf("%lld coconuts, no solution\n", ori);
  }

  return 0;
}
