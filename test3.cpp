/*
/* sort some string
/* first by number of digit, from less to more
/* then by size of string, from long to short
/* then by the alphabet sort.
*/

#include <iostream>
#include <string>
#include <algorithm>
// #include <cstdio>

using namespace std;

struct mystring {
    string s;
    // number of digit in s
    int num_digit;
    mystring() {
        num_digit = 0;
    }
    mystring(string& x) {
        s = x;
        num_digit = get_digit_num(x);
    }

    // determain whether c is number
    static bool is_digit(char c) {
        return c>'0' && c<'9';
    }
    // get numbers of digit in x
    int get_digit_num(const string & x) {
        return count_if(x.begin(), x.end(), this->is_digit);
    }

    // get size of string s.
    int string_size() const  {
        return s.size();
    }
};

bool compare(const mystring& a, const mystring& b)
{
    if (a.num_digit != b.num_digit) {
        return a.num_digit < b.num_digit;
    }
    if (a.string_size() != b.string_size()) {
        return a.string_size() > b.string_size();
    }
    return a.s<b.s;
}

int main()
{
    int n;
    int i = 0;

    // char temp[10000];
    cin >> n;
    // get for last \n of cin. same usage of the following fflush, but more c++.
    // VITAL!!!!
    fflush(stdin);
    // if you really need the n, or I recommand vector instead.
    mystring entry[n];

    string s;
    for(i = 0; i < n; i++) {
        // gets(temp);
        // get one line in c++. without the last \n
        getline(cin, s);
        // in c++ if you use the `mystring entry[n]`, all the n object is constructed. 
        // so here is assignment, not construction.
        entry[i] = mystring(s);
    }

    sort(entry, entry+n, compare);

    for(i = 0; i < n; i++)
    {
        cout << entry[i].s;
        if (i < n-1) cout << endl;
    }
    return 0;
}