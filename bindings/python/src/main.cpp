
#include <pybind11/pybind11.h>

#define STRINGIFY(x)       #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

void generate_calculator_bindings(pybind11::module_& m);
void generate_errors_bindings(pybind11::module_& m);

PYBIND11_MODULE(calculatorpy, m) {
    m.doc() = "Docs for calculator python bindings";

    generate_calculator_bindings(m);
    generate_errors_bindings(m);

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}