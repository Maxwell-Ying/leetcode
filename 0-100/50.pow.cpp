// pow(x, n)


#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;


// MEET TOO MANY STACKOVERFLOW HERE, NEVER WANT MEET THIS AGAIN.


class Solution {
public:
  double myPow1(double x, int n) {
    double ret = 1;
    if (n == 0) { return ret; }
    if (x == 0) { return 0; }
    if (x == 1) { return 1; }
    if (x == -1) { return n%2? -1 : 1; }
    if (n >= 1073741824 || n < -1073741824) {
      return 0;
    }
    int nabs = n;
    if (n<0) {
      nabs = -1*n;
      if (x < 1 && x > -1) {
        x = 1/x;
        n = -1*n;
      }
    }
    int p = 1;
    double b = x;
    vector<int> powers{};
    vector<double> bs{};
    
    

    while (p <= nabs) {
      powers.push_back(p);
      bs.push_back(b);
      auto ptr = powers.data();
      p *= 2;
      b = b*b;
    }

    while (nabs > 0 && !powers.empty()) {
      int tmp = powers.back();
      powers.pop_back();
      if (nabs >= tmp) {
        auto d = powers.size();
        ret *= bs[d];
        nabs -= tmp;
      }
    }

    if (n<0) {
      return 1/ret;
    }
    return ret;
  }

  double myPow(double x, int n) {
    double ret = do_pow(x, n);
    if (n < 0) return 1/ret;
    return ret;
  }

  double do_pow(double x, int n) {
    if (n == 0) {
      return 1;
    }
    if (n%2) {
      double tmp = do_pow(x, n>>1);
      return tmp * tmp * x;
    } else {
      double tmp = do_pow(x, n>>1);
      return tmp * tmp;
    }
  }
};

double data1 = 2.1;
int data2 = 3;

int main() {
  Solution s;
  cout << s.myPow(data1, data2) << endl;
  return 0;
}
