#ifndef _ERRORS_H
#define _ERRORS_H

#include <stdexcept>

namespace Calculator
{
    class CalcError : public std::runtime_error
    {
    public:
        explicit CalcError(const char *message) : std::runtime_error(message) {}
    };
}

#endif