#include <iostream>
#include <string>

using namespace std;

int same(const string & a, const string & b, int offset_of_a) {
    int offset_of_b = 0;
    if (offset_of_a < 0) {
        offset_of_b = 0-offset_of_a;
        offset_of_a = 0;
    }
    int la = a.size() - offset_of_b; 
    int lb = b.size() - offset_of_a;
    
    int l = la<lb? la : lb;
    int ret = 0;
    int m = 0;
    for (auto i=0; i<l; i++) {
        if (a[i+offset_of_b] == b[i+offset_of_a]) {
            ret += 1;
            if (ret > m) {
                m = ret;
            }
        } else {
            ret = 0;
        }
    }
    return m;
}

int main() {
    string s1{"abcedfg"}, s2{"bcd999"};
    // cin >> s1 >> s2;
    
    int m = 0;
    int x = 0-s1.size();
    int y = s2.size();
    
    for (int i=x; i<y; i++) {
        int tmp = same(s1, s2, i);
        if (tmp > m) {
            m = tmp;
        }
    }
    cout << m << endl;
    return 0;
}