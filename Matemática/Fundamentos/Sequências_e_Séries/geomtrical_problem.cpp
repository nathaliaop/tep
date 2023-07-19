// https://codeforces.com/problemset/problem/51/D

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

bool pg(vector<int> arr, int zeros) {
  int n = arr.size();
  ld r = 0;
  if (arr[0] != 0) r = (ld)arr[1] / arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] != arr[i - 1] * r) return false;
  }
  return true;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
 
  int n; cin >> n;
  vector<int> arr(n);

  int zeros = 0;
  bool all_zeros_except_last = true;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] == 0) zeros++;
    if (i != n - 1 && arr[i] != 0) all_zeros_except_last = false;
  }

  if (zeros == n || n == 1 || pg(arr, zeros)) cout << "0\n";
  else if (n == 2) cout << "1\n";
  else if (zeros == 1) {
    auto it = arr.begin();
    while (it != arr.end()) {
      if (*it == 0) it = arr.erase(it);
      else it++;
    }
 
    if (pg(arr, zeros)) cout << "1\n";
    else cout << "2\n";
  }
  else {
    bool is_pg = true;
    ld r = 0;
    if (arr[1] != 0) r = (ld)arr[2] / arr[1];
    for (int i = 2; i < n; i++) {
      if (arr[i] != arr[i - 1] * r) is_pg = false;
    }

    if (is_pg) {
      cout << "1\n";
      return 0;
    }

    if (arr[0] != 0) r = (ld)arr[1] / arr[0];
    int qnt = 0;

    auto it = arr.begin();
    it++;

    while (next(it) != arr.end()) {
      if (*it != *prev(it) * r) {
        if (qnt == 0 && *next(it) == *prev(it) * r) {
          qnt = 1;
          it = arr.erase(it);
        } else {
          qnt = -1;
          break;
        }
      } else it++;
    }

    int val1 = *prev(arr.end());
    int val2 = *prev(prev(arr.end()));
    if (val1 != val2 * r && qnt == 1) qnt = -1;

    if (qnt != -1) cout << "1\n";
    else cout << "2\n";
  }

  return 0;
}
