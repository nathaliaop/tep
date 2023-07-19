// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=442

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

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

void Erase(ordered_set<int>& a, int x){
    int r = a.order_of_key(x);
    auto it = a.find_by_order(r);
    a.erase(it);
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int k; cin >> k;
  while (k--) {
    int m, n; cin >> m >> n;
    int add[m], get[n];
    ordered_set<int> os;

    for (int i = 0; i < m; i++) {
      cin >> add[i];
    }

    for (int i = 0; i < n; i++) {
      cin >> get[i];
    }

    int pos = 0, small = 0;
    for (int i = 0; i < n; i++) {
      int qnt = get[i];
      if (i > 0) qnt -= get[i - 1];

      while (qnt--) {
        os.insert(add[pos]);
        pos++;
      }

      small++;
      cout << *(os.find_by_order(small - 1)) << '\n';
    }

    if (k > 0) cout << '\n';
  }

  return 0;
}
