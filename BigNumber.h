#ifndef BIGNUMBER
#define BIGNUMBER
#include <vector>

class BigNumber {
public:
    BigNumber();
    BigNumber(const int n);
    BigNumber(const std::vector<int> &n);
    BigNumber operator+(const BigNumber& rhs) const ;
    
private:
    std::vector<int> digits;
};

#endif