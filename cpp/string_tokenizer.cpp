// string::find
#include <iostream>       // std::cout
#include <string>         // std::string
#include <sstream>
#include <vector>

// using namespace std;
std::vector<std::string> split(const std::string &in) {
    std::stringstream ss(in);
    std::string s;
    std::vector<std::string> vec;
    
    while (std::getline(ss, s, ' ')) {
        vec.insert(vec.end(),s);
    }

    return vec;
}

int main ()
{
  std::vector<std::string> vec = split("bla bla");

  for (auto str : vec)
  {
    std::cout << str << std::endl;
  }

  return 0;
}
