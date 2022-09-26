package calc

import (
	"testing"
)

func TestCalc(t *testing.T) {
	c := Calculator_create(4)
	c.Add(6)
	c.Mul(5)
	c.Div(2)
	c.Sub(5)
	if c.Result() != 20 {
		t.Error("expected 20")
	}
	c.Destroy()
}
