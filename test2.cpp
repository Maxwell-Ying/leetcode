#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Mdate
{
    int day;
    string month;
    int month_n;
    int year;
};

bool mdate_less(const Mdate& a, const Mdate& b) {
    if (a.year != b.year) {
        return a.year < b.year;
    }
    if (a.month_n != b.month_n) {
        return a.month_n < b.month_n;
    }
    return a.day < b.day;
}

string month_name[20] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", 
                         "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", 
                         "koyab", "cumhu", "uayet"};

int main()
{
    int T;
    cin >> T;
    int i = 0;
    while(i < T)
    {
        int n;  //question number.
        cin >> n;
        char tmp;
        vector <Mdate> mdate(n);
        for (int j = 0; j < n; j++)
        {
            cin >> mdate[j].day >> tmp >> mdate[j].month >> mdate[j].year;
            for (int k=0; k<19; k++) {
                if (mdate[j].month == month_name[k]) {
                    mdate[j].month_n = k;
                    break;
                }
            }
        }

        sort(mdate.begin(), mdate.end(), mdate_less);
        cout << "case #" << i << ":" << endl;
        for (int j = 0; j < n; j++) {
            cout << mdate[j].day << ". " << mdate[j].month << " " << mdate[j].year;
            if (j < (n-1)) cout << endl;
        }
        if (i < (T-1)) cout << endl;
        i++;
    }
    return 0;
}