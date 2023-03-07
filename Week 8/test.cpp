#include <stdlib.h>

#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;

int main() {
    string a = "abc";
    string b = "cba";
    if (a.find(b) != string::npos) {
        std::cout << "found!" << '\n';
    }
}