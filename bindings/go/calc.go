package calc

// if libcalculator and libcalculator_c are already installed, this works
// otherwise we an manually build from the c bindings directory and
// include the following flags:
// CFLAGS: -I../c/include
// LDFLAGS: -L../c/build/

// #cgo LDFLAGS: -lcalculator_c
// #include <calc/calc_c.h>
import "C"

type Calculator struct {
	_c *C.calculator_t
}

func Calculator_create(init_value float64) *Calculator {
	c := C.calculator_create(C.double(init_value))
	return &Calculator{_c: c}
}

func (c *Calculator) add(a float64) *Calculator {
	C.calculator_add(c._c, C.double(a))
	return c
}

func (c *Calculator) sub(a float64) *Calculator {
	C.calculator_sub(c._c, C.double(a))
	return c
}

func (c *Calculator) mul(a float64) *Calculator {
	C.calculator_mul(c._c, C.double(a))
	return c
}

func (c *Calculator) div(a float64) *Calculator {
	C.calculator_div(c._c, C.double(a))
	return c
}

func (c *Calculator) result() float64 {
	return float64(C.calculator_result(c._c))
}

func (c *Calculator) destroy() {
	C.calculator_destroy(c._c)
}
