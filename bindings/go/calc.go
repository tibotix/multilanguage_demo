package main

// ( if libcalculator and libcalculator_c are already installed, this works )
// ( otherwise we an manually build from the c bindings directory and )
// ( include the directory for linking with: -L../c/build/ )

// #cgo CFLAGS: -I../c/include
// #cgo LDFLAGS: -lcalculator_c
// #include "calc_c.h"
import "C"

type calculator struct {
	_c *C.calculator_t
}

func calculator_create(init_value float64) *calculator {
	c := C.calculator_create(C.double(init_value))
	return &calculator{_c: c}
}

func (c *calculator) add(a float64) *calculator {
	C.calculator_add(c._c, C.double(a))
	return c
}

func (c *calculator) sub(a float64) *calculator {
	C.calculator_sub(c._c, C.double(a))
	return c
}

func (c *calculator) mul(a float64) *calculator {
	C.calculator_mul(c._c, C.double(a))
	return c
}

func (c *calculator) div(a float64) *calculator {
	C.calculator_div(c._c, C.double(a))
	return c
}

func (c *calculator) result() float64 {
	return float64(C.calculator_result(c._c))
}

func (c *calculator) destroy() {
	C.calculator_destroy(c._c)
}
