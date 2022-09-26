package calc

import (
	"testing"
)

func TestCalc(t *testing.T) {
	c := Calculator_create(4)
	c.add(6)
	c.mul(5)
	c.div(2)
	c.sub(5)
	if c.result() != 20 {
		t.Error("expected 20")
	}
	c.destroy()
}
