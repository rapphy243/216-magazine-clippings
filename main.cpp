#include <iostream>
#include <vector>
#include "src/magazineClippings.hpp"


using namespace std;

int main() {
  cout << to_string(canCreateNote("a", vector<string>{"a"})) << endl;
  cout << to_string(canCreateNote("a", vector<string>{"ab"})) << endl;
  cout << to_string(canCreateNote("a", vector<string>{"a", "b"})) << endl;
  cout << to_string(canCreateNote("abc", vector<string>{"a", "b", "c"})) << endl;
  cout << to_string(canCreateNote("The bird is red!", vector<string>{"I write a lot.", "To and fro.", "Here be deadly dragons!"})) << endl;
  cout << to_string(canCreateNote("a", vector<string>{"b"})) << endl;
  cout << to_string(canCreateNote("a", vector<string>{"bc"})) << endl;
  cout << to_string(canCreateNote("a", vector<string>{"b", "c"})) << endl;
  cout << to_string(canCreateNote("abc", vector<string>{"a", "b", "d"})) << endl;
  cout << to_string(canCreateNote("The bird is red", vector<string>{"I write a lot.", "To and fro."})) << endl;
  cout << to_string(canCreateNote("The bird is red!", vector<string>{"I write a lot.", "To and fro.", "Here be deadly dragons"})) << endl;
}
