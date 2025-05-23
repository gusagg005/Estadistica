import numpy as np
import statsmodels.api as sm

def regresion_lineal():
    print("\n=== Modelo de Regresión Lineal ===")
    try:
        x = input("Ingrese los valores de X separados por comas: ")
        y = input("Ingrese los valores de Y separados por comas: ")

        x = [float(i.strip()) for i in x.split(",")]
        y = [float(i.strip()) for i in y.split(",")]

        if len(x) != len(y):
            print("Los vectores X y Y deben tener la misma longitud.")
            return

        X = sm.add_constant(x)
        modelo = sm.OLS(y, X).fit()

        print("\nResumen del modelo:")
        print(modelo.summary())
    except Exception as e:
        print(f"Error: {e}")

regresion_lineal()