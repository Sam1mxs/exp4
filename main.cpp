#include "BigNumber.h"
#include <iostream>
using namespace std;

int main() {
    BigNumber a(1231), b("32999"), c;
    c = a * b;
    cout << a.to_string() << endl;
    cout << b.to_string() << endl;
    cout << c.to_string() << endl;
    
}
