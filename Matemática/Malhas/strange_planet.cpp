// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1905

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
#define ld long double
#define pii pair<int, int>

using namespace std;

const ll MAX = (ll)2e9+10;

set<pii> st;
pii get_coordinate(int n) {
    int x = 0, y = 0;

    auto it = st.upper_bound({n, MAX});

    int circle = (*it).ss;
    n = (*it).ff - n;
    y -= (*it).ss;

    // subir circle
    // esquerda circle
    // descer circle - 1
    // descer y 1
    // direita circle
    vector<pii> dir = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
  
    for (int i = 0; i < 4; i++) {
      if (i == 2) circle--;

      if (n - circle <= 0) {
        while (n > 0) {
          x += dir[i].ff;
          y += dir[i].ss;
          n--;
        }
        break;
      }

      x += circle * dir[i].ff;
      y += circle * dir[i].ss;
      n -= circle;

      if (i == 2) {
        y--;
        n--;
        circle++;
      }
    }

    return mp(x, y);
}

ld euclidean_distance(pii a, pii b) {
  return sqrt((a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss));
} 

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int curr = 3;
  int start = 7;
  int r = 4;
  int i = 1;
  while (curr < MAX) {
    st.insert(mp(curr, i));
    i++;
    curr += start;
    start += r;
  }

  int a, b;
  while (cin >> a >> b) {
    if (a == -1 && b == -1) break;
    pii house_a = get_coordinate(a);
    pii house_b = get_coordinate(b);

    cout << fixed << setprecision(2) << euclidean_distance(house_a, house_b) << '\n';
  }

  return 0;
}
