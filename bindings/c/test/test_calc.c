#include <stdio.h>
#include "calc_c.h"

int main(int argc, char **argv)
{
    calculator_t *c = calculator_create(4);
    calculator_add(c, 6);
    calculator_mul(c, 5);
    calculator_div(c, 2);
    calculator_sub(c, 5);
    printf("%f\n", calculator_result(c));
    calculator_destroy(c);
    return 0;
}