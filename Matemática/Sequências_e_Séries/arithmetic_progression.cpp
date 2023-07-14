// https://codeforces.com/problemset/problem/382/C

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

bool is_pa(vector<int> v) {
  sort(v.begin(), v.end());
  int n = v.size();
  int r = v[1] - v[0];
  for (int i = 1; i < n; i++) {
    if (v[i] - v[i - 1] != r) return false;
  }
  return true;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  vector<int> v;
  for (int i = 0, a; i < n; i++) {
    cin >> a;
    v.pb(a);
  }

  if (n == 1) {
    cout << "-1\n";
    return 0;
  }

  sort(v.begin(), v.end());

  int r = v[1] - v[0];

  // if (v[0] == v[1]) cout << "1\n" << v[0] << '\n';
  if (n <= 3) {
    // entre o 1 e o segundo
    // entre o ultimo e o penultimo
    // no final
    // no começo
    set<int> ans;
    int val1 = (v[1] - v[0]) / 2 + v[0];
    int val2 = (v[n - 1] - v[n - 2]) / 2 + v[1];
    int val3 = v[0] - r;
    int val4 = v[n - 1] + r;
    v.pb(val1);
    if (is_pa(v)) ans.insert(val1);
    v.pop_back();
    v.pb(val2);
    if (is_pa(v)) ans.insert(val2);
    v.pop_back();
    v.pb(val3);
    if (is_pa(v)) ans.insert(val3);
    v.pop_back();
    v.pb(val4);
    if (is_pa(v)) ans.insert(val4);
    v.pop_back();

    cout << ans.size() << '\n';
    for (auto e : ans) {
      cout << e << ' ';
    }
    cout << '\n';
  } else if (is_pa(v)) {
    set<int> ans;
    ans.insert(v[0] - r);
    ans.insert(v[n - 1] + r);
    cout << ans.size() << '\n';
    for (auto e : ans) {
      cout << e << ' ';
    }
    cout << '\n';
  } else {
    if (v[1] - v[0] != v[n - 1] - v[n - 2]) {
      if (v[n - 1] - v[n - 2] == v[n - 2] - v[n - 3]) r = v[n - 1] - v[n - 2];
    }
    
    int ans = 0;
    for (int i = 1; i < n; i++) {
      if (v[i] - v[i - 1] != r) {
        ans = v[i - 1] + r;
        v.pb(v[i - 1] + r);
        break;
      }
    }

    if (!is_pa(v)) cout << "0\n";
    else {
      cout << 1 << '\n';
      cout << ans << '\n';
    }
  }

  return 0;
}
