#include "BigNumber.h"

BigNumber::BigNumber() {
    digits.push_back(0);
}

BigNumber::BigNumber(const int n) {
    int tmp = n;
    do {
        digits.push_back(tmp % 10);
        tmp /= 10;
    } while(tmp);
}

BigNumber::BigNumber(const std::vector<int> &n) : digits(n) {}

BigNumber BigNumber::operator+(const BigNumber& rhs) const {
    std::vector<int> result;
    const std::vector<int>& a = rhs.digits;
    const std::vector<int>& b = this->digits;
    result.resize(std::max(a.size(), b.size()));
    int tmp = 0;
    for(size_t i = 0; i < a.size() && i < b.size(); i++) {
        tmp += a[i] + b[i];
        result[i] = tmp % 10;
        tmp /= 10;
    }
    if(tmp) result.push_back(tmp);
    return result;
}
