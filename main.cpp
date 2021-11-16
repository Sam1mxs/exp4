#include "BigNumber.h"
#include <iostream>
using namespace std;

int main() {
    BigNumber a(1), b(2), c;
    c = a + b;
    cout << c.to_string();
    
}
