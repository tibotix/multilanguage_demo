package main

import (
	"fmt"
)

func main() {
	c := calculator_create(4)
	c.add(6)
	c.mul(5)
	c.div(2)
	c.sub(5)
	fmt.Printf("%f\n", c.result())
	c.destroy()
}
