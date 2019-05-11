#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int divide(int dividend, int divisor) {
    if (dividend == 0) {
      return 0;
    }

    if (divisor == -2147483648) {
      return dividend > 0 ? 0 : 1;
    }

    if (dividend == -2147483648) {
        if (divisor > 0) {
            int tmp = divide(dividend + divisor, divisor);
            if (tmp == 2147483647) {
                return 2147483647;
            } else {
                return tmp-1;
            }
        } else {
            int tmp = divide(dividend + (0-divisor), divisor);
            if (tmp == 2147483647) {
                return 2147483647;
            } else {
                return tmp+1;
            }
        }
    }
    auto uandb = udivide(abs(dividend), abs(divisor));
    unsigned int uret = uandb.first;
    bool yushu = uandb.second;
    if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
      return uret;
    } else {
      return 0 - static_cast<int>(uret);
    } 
  }

  pair<unsigned int, bool> udivide(unsigned int dividend, unsigned int divisor) {
    if (dividend < divisor) {
      return make_pair(0, true);
    }
    if (dividend == divisor) {
      return make_pair(1, false);
    }
    if (divisor == 1) {
      return make_pair(dividend, false);
    }
    unsigned int ret = 0;
    unsigned int powdivisor = divisor;
    while (powdivisor < dividend && (powdivisor < (1<<30))) {
      powdivisor <<= 1;
    }
    while (powdivisor >= divisor) {
      ret <<= 1;
      if (dividend >= powdivisor) {
        ret += 1;
        dividend -= powdivisor;
      }
      powdivisor >>= 1;
    }
    return make_pair(ret, dividend != 0);
  }
};

int data1 = -1020450018;
int data2 = 2091335377;

int main() {
  Solution s;
  cout << s.divide(data1, data2) << endl;
  return 0;
}