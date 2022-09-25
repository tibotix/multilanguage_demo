import pytest
import calculatorpy

def test_calculator_add(calculator):
    calculator.add(5)
    assert calculator.result() == 5.0

def test_calculator_sub(calculator):
    calculator.sub(5)
    assert calculator.result() == -5.0

def test_calculator_mul(calculator):
    calculator.mul(5)
    assert calculator.result() == 0.0
    calculator.add(5)
    calculator.mul(5)
    assert calculator.result() == 25.0

def test_calculator_div(calculator):
    calculator.div(5)
    assert calculator.result() == 0.0
    calculator.add(25)
    calculator.div(5)
    assert calculator.result() == 5.0

def test_calculator_div_zero(calculator):
    with pytest.raises(calculatorpy.CalcError):
        calculator.div(0)

def test_calculator_chaining(calculator):
    assert calculator.add(10).div(2.5).add(1.5).mul(2).result() == 11

