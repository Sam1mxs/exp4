#ifndef BIGNUMBER
#define BIGNUMBER
#include <vector>
#include <string>

class BigNumber {
public:
    BigNumber();
    BigNumber(const int n);
    BigNumber(const std::string &n);
    BigNumber(const std::vector<int> &n);
    BigNumber operator+(const BigNumber& rhs) const ;
    BigNumber operator*(const BigNumber& rhs) const ;
    std::string to_string() const ;
    
private:
    std::vector<int> digits;
};

#endif