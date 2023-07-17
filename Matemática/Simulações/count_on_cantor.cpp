// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=200

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

const int MAX = 2e7+10;

// 1                1
// 2 => 3 (desce)   2   coluna 2   fileira 1
// 3 => 6 (sobe)    3   coluna 1    fileira 3 
// 4 => 10 (desce)  4   coluna 4    fileira 1

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  set<int> st;
  int curr = 1;
  int r = 1;
  int add = 1;
  int i = 1;
  map<int, int> m;
  while (curr < MAX) {
    st.insert(curr);
    m[curr] = i;
    add += r;
    curr += add;
    i++;
  }

  int n;
  while (cin >> n) {
    auto it = st.lower_bound(n);
    int curr = *it;
    int idx = m[curr];
    int first = 1, second = 1;
    if (idx % 2 == 0) first = idx;
    else second = idx;
    pii dir;
    if (idx % 2 == 0) dir = mp(-1, 1);
    else dir = mp(1, -1);
    while (curr != n) {
      first += dir.ff;
      second += dir.ss;
      curr--;
    }

    cout << "TERM " << n << " IS " << first << "/" << second << '\n';
  }
  
  return 0;
}
