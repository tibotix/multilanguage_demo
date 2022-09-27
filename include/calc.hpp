#ifndef _CALC_H
#define _CALC_H

#include <stdint.h>

namespace Calculator {


class Calculator {
public:
    explicit Calculator(double init_value) : m_result{init_value} {}
    Calculator& add(const double& a);
    Calculator& sub(double a);
    Calculator& mul(double a);
    Calculator& div(double a);
    double result() const {
        return m_result;
    }

private:
    double m_result;
};
}

#endif