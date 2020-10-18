#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  map<char, int> ops{{'-', 1}, {'+', 1}, {'*', 2}, {'/', 2}, {'^', 3}};
  stack<char> t;
  string s;

  int n;
  cin >> n;
  while (n--) {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (c == '(') {
        t.push(c);
        continue;
      }
      if (c == ')') {
        char ti = t.top();
        while (ti != '(') {
          cout << ti;
          t.pop();
          ti = t.top();
        }
        t.pop();
        continue;
      }
      auto search = ops.find(c);
      if (search != ops.end()) { // it is an operator
        if (t.empty()) {
          t.push(c);
        } else {
          char ti = t.top();
          if (ti == '(') {
            t.push(c);
          } else if (ops[c] > ops[ti]) {
            t.push(c);
          } else {
            while (ops[ti] >= ops[c]) {
              cout << ti;
              t.pop();
              if (t.empty()) {
                break;
              }
              ti = t.top();
              if (ti == '(') {
                break;
              }
            }
            t.push(c);
          }
        }
      } else {
        cout << c;
      }
    }
    while (!t.empty()) {
      cout << t.top();
      t.pop();
    }
    cout << endl;
  }
  return 0;
}
