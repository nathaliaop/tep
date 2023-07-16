// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=1174

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
#define ld long double
#define ll long long
#define int long long
#define pii pair<int, int>

using namespace std;

const ll MAX = (ll)3e9+10;

set<pii> st;

pair<ld, ld> get_coordinates(int n) {
  auto it = st.upper_bound(mp(n, MAX));
  it--;

  ld H = sqrt(3) / 2;
  ld A = sqrt(3) / 6;
  ld y = -(*it).ss * H; // * height H
  ld x = -(*it).ss * 0.5; // * 1 km
  
  n -= (*it).ff;
  if (n % 2 == 0) y += A;
  else y += H - A;

  x += (n + 1) * 0.5;

  return mp(x, y);
}

ld euclidean_distance(pair<ld, ld> a, pair<ld, ld> b) {
  return sqrt((a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss));
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  // 2  1 => 3
  // 3  2 => 5  => 8
  // 4  3 => 7  -> 15
  int curr = 1;
  int row = 1;
  int r = 2;
  int i = 1;
  st.insert(mp(0, 0));
  while (curr < MAX) {
    st.insert(mp(curr, i));
    row += r;
    curr += row;
    i++;
  }

  //   1   + h * h =  1     h * h = 3 / 4  = > sqrt(3)  / 2
  //   4    
  //
  //   a => h / 3 => sqrt(3) / 6

  int n, m;
  while (cin >> n >> m) {
    cout << fixed << setprecision(3) << euclidean_distance(get_coordinates(n), get_coordinates(m)) << '\n';
  }

  return 0;
}
