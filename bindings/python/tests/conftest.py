import pytest
import calculatorpy


@pytest.fixture()
def calculator():
    return calculatorpy.Calculator(0)