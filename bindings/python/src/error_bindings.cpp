#include <pybind11/pybind11.h>
#include "errors.h"

void generate_errors_bindings(pybind11::module_& m) {
    pybind11::register_local_exception<Calculator::CalcError>(m, "CalcError", PyExc_RuntimeError);
}
