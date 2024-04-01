#include "safe_math.h"

#include <limits>
#include <stdexcept>
#include <string>


static const int kMax = std::numeric_limits<int>::max();
static const int kMin = std::numeric_limits<int>::min();

int SafeMath::Add(int x, int y) {
    if (x > 0 && y > 0) {
        if (x > kMax - y) {
            std::string m = "Interger overflow occurs in ";
            m += std::to_string(x) + " + ";
            m += std::to_string(y) + ".";
            throw std::overflow_error(m);
        }
    } else if (x < 0 && y < 0) {
        if (x < kMin - y) {
            std::string m = "Interger overflow occurs in ";
            m += std::to_string(x) + " + ";
            m += std::to_string(y) + ".";
            throw std::overflow_error(m);
        }
    }

    return x + y;
}

int SafeMath::Sub(int x, int y) {
    if (x > 0 && y < 0) {
        if (x > kMax + y) {
            std::string m = "Interger overflow occurs in ";
            m += std::to_string(x) + " - ";
            m += std::to_string(y) + ".";
            throw std::overflow_error(m);
        }
    } else if (x < 0 && y > 0) {
        if (x < kMin + y) {
            std::string m = "Interger overflow occurs in ";
            m += std::to_string(x) + " - ";
            m += std::to_string(y) + ".";
            throw std::overflow_error(m);
        }
    }

    return x - y;
}

int SafeMath::Mul(int x, int y) {
    if (x > kMax / y) {
        std::string m = "Interger overflow occurs in ";
        m += std::to_string(x) + " * ";
        m += std::to_string(y) + ".";
        throw std::overflow_error(m);
    } else if (x < kMin / y) {
        std::string m = "Interger overflow occurs in ";
        m += std::to_string(x) + " * ";
        m += std::to_string(y) + ".";
        throw std::overflow_error(m);
    }

    return x * y;
}


int SafeMath::Div(int x, int y) {
    if (y == 0) {
        std::string m = "Divide-by-zero exception occurs in ";
        m += std::to_string(x) + " / ";
        m += std::to_string(y) + ".";
        throw std::overflow_error(m);
    }

    return x / y;
}

int SafeMath::Mod(int x, int y) {
    if (y == 0) {
        std::string m = "Divide-by-zero exception occurs in ";
        m += std::to_string(x) + " % ";
        m += std::to_string(y) + ".";
        throw std::overflow_error(m);
    }

    return x % y;
}
