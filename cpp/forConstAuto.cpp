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
    
    cout << "=== Before const auto For Loop ===" << std::endl;
    for (const auto s : sList) { }
    
    cout << "=== Between For Loops ===" << std::endl;
    
    for (const auto& s : sList) { }
    cout << "=== After const auto& For Loops ===" << std::endl;    
    
    return 0;
}

