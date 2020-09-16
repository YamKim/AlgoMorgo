#include <iostream>

using namespace std;

void func2(void) {
    cout << "Hello World!" << "\n";
}

void func1(void) {
    func2();
}

int main(void) {
    func1();

    return (0);
}
