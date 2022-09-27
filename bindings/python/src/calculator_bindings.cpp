

#include <pybind11/pybind11.h>

#include "calc.hpp"

void generate_calculator_bindings(pybind11::module_& m) {
    auto calc = pybind11::class_<Calculator::Calculator>(m, "Calculator");
    calc.def(pybind11::init<double>());
    calc.def("__copy__", [](Calculator::Calculator& self) {
        return Calculator::Calculator(self);
    });
    calc.def("add", &Calculator::Calculator::add);
    calc.def("sub", &Calculator::Calculator::sub);
    calc.def("mul", &Calculator::Calculator::mul);
    calc.def("div", &Calculator::Calculator::div);
    calc.def("result", &Calculator::Calculator::result);
}