#include <stdlib.h>
#include <new>
#include "calc.hpp"
#include "errors.hpp"
#include "calc_c.h"
#include "ffi_utils.h"

struct _CalculatorWrapper {
    void* obj;
};

calculator_t* calculator_create(double init_value) {
    calculator_t* c = static_cast<calculator_t*>(malloc(sizeof(*c)));
    Calculator::Calculator* obj = new (std::nothrow) Calculator::Calculator(init_value);
    c->obj = obj;
    return c;
}

void calculator_destroy(calculator_t* c) {
    CHECK(c);
    delete CASTOBJ(Calculator::Calculator, c);
    free(c);
}

void calculator_add(calculator_t* c, double a) {
    CHECK(c);
    GETOBJ(obj, Calculator::Calculator, c);
    obj->add(a);
}

void calculator_sub(calculator_t* c, double a) {
    CHECK(c);
    GETOBJ(obj, Calculator::Calculator, c);
    obj->sub(a);
}

void calculator_mul(calculator_t* c, double a) {
    CHECK(c);
    GETOBJ(obj, Calculator::Calculator, c);
    obj->mul(a);
}

void calculator_div(calculator_t* c, double a) {
    CHECK(c);
    GETOBJ(obj, Calculator::Calculator, c);
    TRY(obj->div(a);, Calculator::CalcError);
}

double calculator_result(calculator_t* c) {
    CHECK(c, 0);
    GETOBJ(obj, Calculator::Calculator, c);
    return obj->result();
}
