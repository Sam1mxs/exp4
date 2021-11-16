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


BigNumber::BigNumber(const std::string &n) {
    for(size_t i = n.size(); i; i--) {
        digits.push_back(n[i - 1] - '0');
    }
}

BigNumber BigNumber::operator+(const BigNumber& rhs) const {
    std::vector<int> result;
    const std::vector<int>& a = rhs.digits;
    const std::vector<int>& b = this->digits;
    int tmp = 0;
    size_t i = 0;
    while(i < a.size() || i < b.size()) {
        if(i < a.size()) tmp += a[i];
        if(i < b.size()) tmp += b[i];
        result.push_back(tmp % 10);
        tmp /= 10;
        i++;
    }
    if(tmp) result.push_back(tmp);
    return result;
}

BigNumber BigNumber::operator*(const BigNumber& rhs) const {
    std::vector<int> result;
    const std::vector<int>& a = rhs.digits;
    const std::vector<int>& b = this->digits;
    result.resize(a.size() + b.size(), 0);
    for(size_t i = 0; i < a.size(); i++) {
        for(size_t j = 0; j < b.size(); j++) {
            result[i + j] += a[i] * b[j];
            result[i + j + 1] += result[i + j] / 10;
            result[i + j] %= 10; 
        }
    }
    while(result.size() > 1 && result.back() == 0) result.pop_back();
    return result;
}

std::string BigNumber::to_string() const {
    std::string result;
    for(size_t i = digits.size(); i; i--) {
        result.push_back(digits[i - 1] + '0');
    }
    return result;
}
