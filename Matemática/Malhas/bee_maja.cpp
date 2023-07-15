// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1123

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

const int MAX = 1e5+10;
const ll INF = 1e18+10;

int arr[MAX];

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int curr = 2;
  int start = 7;
  int r = 6;
  int i = 1;
  set<pii> st;
  while(curr < MAX) {
    st.insert(mp(curr, i));
    i++;
    curr += start;
    start += r;
  }

  int n;
  while (cin >> n) {
    int x = 0, y = 0;
    if (n == 1) {
      cout << x << ' ' << y << '\n';
      continue;
    }

    auto it = st.upper_bound(mp(n, INF));
    it--;
    int circle = (*it).ss;
    n -= (*it).ff;
    y += circle;

    vector<pii> dir = {{-1, 0}, {0, -1}, {1, -1}, {1, 0}, {0, 1}, {-1, 1}};

    for (int i = 0; i < 6; i++) {
      if (i == 4) circle++;

      if (n - circle <= 0) {
        while (n > 0) {
          n--;
          x += dir[i].ff;
          y += dir[i].ss;
        }

        break;
      }

      x += circle * dir[i].ff;
      y += circle * dir[i].ss;
      n -= circle;
      if (i == 4) circle--;
    }

    cout << x << ' ' << y << '\n';

  }

  return 0;
}
