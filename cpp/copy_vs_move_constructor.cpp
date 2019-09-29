#include <iostream>
#include <vector>

using namespace std;

struct S {
  S() { cout << "S()" << endl; }
  S(const S&) {cout << "S(const S&)" << endl; } // Copy Constructor
  S(S&&) {cout << "S(S&&)" << endl; } // Move Constructor
  ~S() {cout << "~S()" << endl; }
};


int main()
{
    vector<S> sList (3);
    
    cout << "\n=== Copy Constructor  ===" << std::endl;
    for (const auto s : sList) { }
    
    cout << "\n=== Move Constructor ===" << std::endl;
    for (const auto& s : sList) { }
    
    return 0;
}

