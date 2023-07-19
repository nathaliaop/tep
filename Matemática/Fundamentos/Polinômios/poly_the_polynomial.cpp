// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=439

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
using polynomial = std::vector<int>;

using namespace std;

vector<string> split(string txt, char key = ' '){
    vector<string> ans;
    
    string palTemp = "";
    for(int i = 0; i < txt.size(); i++){
        
        if(txt[i] == key){
            if(palTemp.size() > 0){
                ans.push_back(palTemp);
                palTemp = "";
            }
        } else{
            palTemp += txt[i];
        }
        
    }
    
    if(palTemp.size() > 0)
        ans.push_back(palTemp);
    
    return ans;
}

int degree(const polynomial& p) {
  return p.size() - 1;
}

int evaluate(const polynomial& p, int x) {
  int y = 0, N = degree(p);

  for (int i = N; i >= 0; --i) {
    y *= x;
    y += p[i];
  }

  return y;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  
  string tmp;
  while (getline(cin, tmp)) {
    vector<string> v = split(tmp);
    polynomial p; // p(x) = xˆ2 - 5x + 6
   
    int n = v.size();
    for (int i = n - 1; i >= 0; i--) {
      p.pb(stoi(v[i]));
    }

    string query; getline(cin, query);
    vector<string> q = split(query);
    int sz = q.size();

    for (int i = 0; i < sz; i++) {
      int x = stoi(q[i]);
      cout << evaluate(p, x);
      if (i != sz - 1) cout << ' ';
    }
    cout << '\n';
  }

  return 0;
}
