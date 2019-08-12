#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  cout << "hello world" << endl;
  getchar();
  return 0;

  vector<vector<pair<uint32_t, bool>>> tmp_adj;
  vector<pair<uint32_t, bool>> adeg;
  unsigned int i;

  for (auto & m: tmp_adj) {
    m.erase(std::remove_if(m.begin(), m.end(), 
    [&](const std::pair<uint32_t, bool> & a){return a.first == adeg[i].first;}), 
    m.end());
  }
}