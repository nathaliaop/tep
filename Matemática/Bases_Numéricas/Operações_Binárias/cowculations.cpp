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

/*
1
17
18

 5

1   2   c   
7 + 8 + 7 = 22

nc 1
c 7    5    = 12 
*/
// add $ remains the same
pair<char, char> add(char a, char b) {
  switch(a) {
    case 'V':
      if (b == 'V') return mp('V', '$');
      if (b == 'U') return mp('U', '$');
      if (b == 'C') return mp('C', '$');
      if (b == 'D') return mp('D', '$');
    case 'U':
      if (b == 'V') return mp('U', '$');
      if (b == 'U') return mp('C', '$');
      if (b == 'C') return mp('D', '$');
      if (b == 'D') return mp('V', 'U');
    case 'C':
      if (b == 'V') return mp('C', '$');
      if (b == 'U') return mp('D', '$');
      if (b == 'C') return mp('V', 'U');
      if (b == 'D') return mp('U', 'U');
    case 'D':
      if (b == 'V') return mp('D', '$');
      if (b == 'U') return mp('V', 'U');
      if (b == 'C') return mp('U', 'U');
      if (b == 'D') return mp('C', 'U');
  }
  if (b != '$') return mp(b, a);
  return mp(a, b);
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  cout << "COWCULATIONS OUTPUT\n";
  while (t--) {
    string num1, num2; cin >> num1 >> num2;
    int q = 3;
    while (q--) {
      char op; cin >> op;
      switch(op) {
        case 'R':
          num2.pop_back();
          num2 = 'V' + num2;
          break;
        case 'L':
          num2 = num2 + 'V';
          break;
        case 'A':
          int sz = num2.size();
          while (num1.size() < sz) {
            num1 = '$' + num1;
          }
          char carry = '$', ncarry = '$';
          string sum = "";
          for (int i = sz - 1; i >= 0; i--) {
            pair<char, char> tmp = add(num2[i], num1[i]);
            char curr = tmp.ff;
            ncarry = tmp.ss;
            tmp = add(curr, carry);
            curr = tmp.ff;
            ncarry = add(ncarry, tmp.ss).ff;
            carry = '$';
            sum += curr;
            swap(carry, ncarry);
          }
          if (carry != '$') sum += carry;
          reverse(sum.begin(), sum.end());
          num2 = sum;
          break;
      }  
    }

    while (num2.size() < 8) {
      num2 = 'V' + num2;
    }

    string res; cin >> res;

    cout << (num2 == res ? "YES\n" : "NO\n");
  }
  cout << "END OF OUTPUT\n";

  return 0;
}
