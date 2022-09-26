import pytest
import calculatorpy


def test_calculator_div_zero(calculator):
    with pytest.raises(calculatorpy.CalcError):
        calculator.div(0)

def test_calculator(calculator):
    assert calculator.add(10).sub(2).add(2).div(2.5).add(1.5).mul(2).result() == 11

