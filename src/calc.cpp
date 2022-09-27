#include "calc.hpp"
#include "errors.hpp"

Calculator::Calculator& Calculator::Calculator::add(const double& a) {
    m_result = m_result + a;
    return *this;
}

Calculator::Calculator& Calculator::Calculator::sub(double a) {
    m_result = m_result - a;
    return *this;
}

Calculator::Calculator& Calculator::Calculator::mul(double a) {
    m_result = m_result * a;
    return *this;
}

Calculator::Calculator& Calculator::Calculator::div(double a) {
    if (a == 0) {
        throw CalcError("Division by zero");
    }
    m_result = m_result / a;
    return *this;
}
