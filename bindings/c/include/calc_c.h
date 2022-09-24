#ifndef _CALC_C_H
#define _CALC_C_H
#endif

#ifdef __cplusplus
extern "C"
{
#endif

    struct _CalculatorWrapper;
    typedef struct _CalculatorWrapper calculator_t;

    calculator_t *calculator_create(double init_value);
    void calculator_destroy(calculator_t *c);
    void calculator_add(calculator_t *c, double a);
    void calculator_sub(calculator_t *c, double a);
    void calculator_mul(calculator_t *c, double a);
    void calculator_div(calculator_t *c, double a);
    double calculator_result(calculator_t *c);

#ifdef __cplusplus
}
#endif